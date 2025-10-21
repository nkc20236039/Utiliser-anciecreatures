import os
import re
import subprocess
import datetime

# 対象拡張子
TARGET_EXTS = (".c", ".cpp", ".h", ".hpp", ".cs")

HEADER_START = "/*********************************************************************"
HEADER_END = "*********************************************************************/"

# =====================================================================
# Git情報取得
# =====================================================================
def get_git_timestamp(file_path, first=False):
    """作成日または最終更新日をGitログから取得"""
    cmd = ["git", "log", "--follow", "--format=%ci", "--", file_path]
    result = subprocess.run(cmd, capture_output=True, text=True)
    lines = result.stdout.strip().splitlines()
    if not lines:
        return "unknown"
    timestamp = lines[-1] if first else lines[0]
    date_str = timestamp.split()[0]
    try:
        dt = datetime.datetime.strptime(date_str, "%Y-%m-%d")
        return dt.strftime("%Y/%m/%d")
    except Exception:
        return "unknown"

# =====================================================================
# briefコメント抽出
# =====================================================================
def extract_brief_comment(file_path):
    """
    ファイル先頭からコメントを抽出
    ・ // 単行コメントを連続している場合まとめる
    ・ /* */ 複数行コメントにも対応
    """
    lines = []
    try:
        with open(file_path, "r", encoding="utf-8") as f:
            content = f.read()

        # 複数行コメント（最初に出てきたもののみ）
        m = re.match(r"^\s*/\*([\s\S]*?)\*/", content)
        if m:
            text = m.group(1).strip()
            # コメント内の行頭アスタリスク除去
            text = re.sub(r"^\s*\* ?", "", text, flags=re.MULTILINE)
            return text.splitlines()[0] if text else ""

        # 単行コメント連続パターン
        for line in content.splitlines():
            stripped = line.strip()
            if stripped.startswith("//"):
                lines.append(re.sub(r"^//\s?", "", stripped))
            elif stripped == "":
                continue
            else:
                break
        if lines:
            return " ".join(lines).strip()

    except Exception:
        pass
    return ""

# =====================================================================
# ヘッダー生成
# =====================================================================
def generate_header(file_path, author, created, modified, brief):
    filename = os.path.basename(file_path)
    return f"""{HEADER_START}
 * file   {filename}
 * brief  {brief}
 * 
 * author {author}
 * created {created}
 * last_modified {modified}
 {HEADER_END}
"""

# =====================================================================
# ファイル更新
# =====================================================================
def update_file(file_path, author):
    created = get_git_timestamp(file_path, first=True)
    modified = get_git_timestamp(file_path)
    brief = extract_brief_comment(file_path)

    with open(file_path, "r", encoding="utf-8") as f:
        content = f.read()

    # 既存ヘッダーを削除
    content = re.sub(
        rf"{re.escape(HEADER_START)}[\s\S]*?{re.escape(HEADER_END)}\n?",
        "",
        content,
        flags=re.DOTALL,
    )

    header = generate_header(file_path, author, created, modified, brief)
    new_content = f"{header}\n{content}"

    with open(file_path, "w", encoding="utf-8") as f:
        f.write(new_content)

# =====================================================================
# メイン処理
# =====================================================================
def main():
    author = os.getenv("GITHUB_ACTOR", "unknown")

    for root, _, files in os.walk("."):
        if ".git" in root:
            continue
        for file in files:
            if file.endswith(TARGET_EXTS):
                file_path = os.path.join(root, file)
                update_file(file_path, author)

if __name__ == "__main__":
    main()

#pragma once

#include <vector>
#include <functional>
#include <utility>
#include <type_traits>
#include <cstdint>

template <class>
class Delegate;

template <class Ret, class... Args>
class Delegate<Ret(Args...)> {
public:
	Delegate() = default;
	~Delegate() = default;

	/// <summary>
	/// 関数を追加する
	/// </summary>
	/// <returns>追加した関数の識別ID</returns>
	template <class T>
	std::uint64_t Add(T&& func) {
		// 互換性のチェック
		static_assert(
			std::is_invocable_r_v<Ret, T&, Args...>,
			"Delegate::Add: incompatible callable"  // 互換性の無い呼び出しエラー
			);

		// IDを更新
		m_nextId++;

		// 関数を追加
		m_functions.emplace_back(
			FunctionData{
				m_nextId,
				std::function<Ret(Args...)>(std::forward<T>(func))
			}
		);
		return m_nextId;
	}

	/// <summary>
	/// メンバー関数の追加
	/// </summary>
	/// <returns>追加した関数の識別ID</returns>
	template <class T, class MemFn>
	std::uint64_t Add(T* obj, MemFn memFn) {
		static_assert(
			std::is_member_function_pointer_v<MemFn>,
			"Delegate::Add: memFn must be member function pointer"
			);

		// IDを更新
		m_nextId++;

		// 関数を追加
		m_functions.emplace_back(
			FunctionData{
				m_nextId,
				[obj, memFn](Args... args) -> Ret {
					return std::invoke(memFn, obj, std::forward<Args>(args)...);
				}
			}
		);
		return m_nextId;
	}

	/// <summary>
	/// 登録している関数を削除する
	/// </summary>
	/// <returns>削除に成功したか</returns>
	bool Remove(std::uint64_t id) {
		// 指定されたIDの関数を削除
		auto it = std::remove_if(
			m_functions.begin(),
			m_functions.end(),
			[id](const FunctionData& e) { return e.id == id; }
		);

		// 指定されたIDが見つからない場合終了
		if (it == m_functions.end()) { return false; }

		m_functions.erase(it, m_functions.end());

		return true;
	}

	/// <summary>
	/// 全ての関数を削除する
	/// </summary>
	void Clear() {
		m_functions.clear();
	}

	// 呼び出し
	void Invoke(Args... args) const {
		for (const auto& e : m_functions) {
			e.func(std::forward<Args>(args)...);
		}
	}

private:
	struct FunctionData {
		/*public*/
		std::uint64_t id;
		std::function<Ret(Args...)> func;
	};

	std::vector<FunctionData> m_functions;
	std::uint64_t m_nextId = 0;
};
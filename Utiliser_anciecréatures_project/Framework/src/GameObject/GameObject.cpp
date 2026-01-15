#include "GameObject.h"

void GameObject::UpdateGameObjectState() {
	// エラーモデル(-1)であればスキップ
	if (m_modelHandle == -1) { return; }

	// 描画前の設定
	Library::SetPosition(m_modelHandle, m_transform->Position);
	Library::SetScale(m_modelHandle, m_transform->Scale);
	Library::SetRotation(m_modelHandle, m_transform->Rotation);
	Library::SetVisible(m_modelHandle, m_showModel);
	Library::SetUseModelZBuffer(m_modelHandle, m_zBuffer);
	Library::SetWriteModelZBuffer(m_modelHandle, m_zBuffer);
}

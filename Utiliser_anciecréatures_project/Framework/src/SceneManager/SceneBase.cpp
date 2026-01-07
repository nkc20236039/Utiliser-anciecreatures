#include "SceneBase.h"

void SceneBase::UpdateGameObjects(const Time& time) {
	// 新しいゲームオブジェクトを更新サイクルに追加
	m_gameObjectManager.ProcessSpawn();
	// ゲームオブジェクトを更新
	m_gameObjectManager.Update(time);
	// ゲームオブジェクトを描画
	m_gameObjectManager.Draw();
	// 破棄予定のゲームオブジェクトを更新サイクルから削除
	m_gameObjectManager.ProcessDestroy();
}
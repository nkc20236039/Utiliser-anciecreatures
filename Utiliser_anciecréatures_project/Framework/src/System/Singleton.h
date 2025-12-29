#pragma once

#include <memory>

template<typename T>
class Singleton {
public:
	/// <summary>
	/// シングルトンインスタンスを取得
	/// </summary>
	inline static T& Get() {
		// インスタンスがなければ生成
		if (m_instance == nullptr) {
			m_instance = new T();
		}

		return *m_instance;
	}

	/// <summary>
	/// インスタンスを破棄
	/// </summary>
	inline static void Destroy() {
		delete m_instance;
		m_instance = nullptr;
	}

protected:
	// 外部からの生成を禁止
	Singleton() = default;
	virtual ~Singleton() = default;

private:
	static T* m_instance;	// シングルトンインスタンス

	// コピーを禁止
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;
};

// シングルトンのインスタンス変数を初期化
template<typename T>
T* Singleton<T>::m_instance = nullptr;
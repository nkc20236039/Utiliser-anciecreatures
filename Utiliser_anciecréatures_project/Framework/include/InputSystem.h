#pragma once

#include <vector>
#include <memory>
#include <unordered_set>

#include "Library/Wrapper.h"
#include "Singleton.h"

class InputSystem : public Singleton<InputSystem> {
	friend class Singleton<InputSystem>;
	friend class InputManager;

public:
	/* キー入力 */
	/// <summary>
	/// 対象のキーを押した瞬間であるか判定する
	/// </summary>
	bool IsKeyDown(Library::KeyCode key);
	/// <summary>
	/// 対象のキーを押している状態であるか判定する
	/// </summary>
	bool IsKeyPressing(Library::KeyCode key);
	/// <summary>
	/// 対象のキーを離した瞬間であるか判定する
	/// </summary>
	bool IsKeyUp(Library::KeyCode key);
	/// <summary>
	/// 2つのキーから入力方向を取得する
	/// </summary>
	/// <param name="positive">プラス方向の入力キー</param>
	/// <param name="negative">マイナス方向の入力キー</param>
	float GetAxis(Library::KeyCode positive, Library::KeyCode negative);

	/* マウス入力 */
	/// <summary>
	/// 対象のマウスボタンを押した瞬間であるか判定する
	/// </summary>
	bool IsMouseButtonDown(Library::MouseButton button);
	/// <summary>
	/// 対象のマウスボタンを押している状態であるか判定する
	/// </summary>
	bool IsMouseButtonPressing(Library::MouseButton button);
	/// <summary>
	/// 対象のマウスボタンを離した瞬間であるか判定する
	/// </summary>
	bool IsMouseButtonUp(Library::MouseButton button);
	/// <summary>
	/// マウスの現在座標を取得する
	/// </summary>
	/// <returns></returns>
	Library::float2 GetMousePosition() {
		return Library::GetMousePoint();
	}
	/// <summary>
	/// マウスの移動量を取得する
	/// </summary>
	/// <returns></returns>
	Library::float2 GetMouseDelta();
private:
	enum class InputState {
		Down,
		Pressing,
		Up,
	};

	class InputData {
	public:
		~InputData() = default;

		/// <summary>
		/// キーコードをもとにInputDataを生成する
		/// </summary>
		static InputData GetData(Library::KeyCode code) {
			return InputData(InputDevice::Keyboard, static_cast<int>(code));
		}

		/// <summary>
		/// マウスコードをもとにInputDataを生成する
		/// </summary>
		/// <param name="code"></param>
		/// <returns></returns>
		static InputData GetData(Library::MouseButton code) {
			return InputData(InputDevice::Mouse, static_cast<int>(code));
		}

		/// <summary>
		/// 入力状態を取得する
		/// </summary>
		bool IsStateMatch(const InputData& data, InputState state) const {
			// IDとデバイスが異なる場合はfalseを返す
			if ((m_id != data.m_id) || (m_device != data.m_device)) { return false; }

			return m_state == state;
		}

		bool operator==(const InputData& other) const {
			return (m_id == other.m_id) && (m_device == other.m_device);
		}

		// getter
		InputState GetState() const { return m_state; }
		// setter
		void SetState(InputState state) { m_state = state; }

	private:
		// 入力デバイスの種類
		enum class InputDevice {
			Keyboard,
			Mouse,
		};

		InputData(InputDevice device, int id, InputState state = InputState::Down)
			: m_device(device)
			, m_id(id)
			, m_state(state) {}

		int			m_id;
		InputDevice m_device;
		InputState  m_state;
	};

	InputSystem();
	~InputSystem() = default;

	Library::float2			m_lastMousePos = Library::float2::Zero();	// 前回のフレームのマウス座標
	std::vector<InputData>	m_newInputTempData;		// 新しい入力を一時的に保存するvector
	std::vector<InputData>	m_pressingButtonData;	// 押されているボタンの状態を保存するvector

	/// <summary>
	/// 入力状態の更新を行う
	/// </summary>
	void Update();	// InputManagerから呼び出される

	/// <summary>
	/// 入力の状態が一致するか判定する
	/// </summary>
	bool IsButtonStateMatch(InputData id, InputState state);
};
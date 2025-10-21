#include "SceneStateMachine.h"

template<IsScene T>
void SceneStateMachine::ChangeState() {

}

void SceneStateMachine::Update() {

}

template<IsScene T>
void SceneStateMachine::Register(std::unique_ptr<T> instance) {

}

template<IsScene T>
void SceneStateMachine::Unregister(std::unique_ptr<T> instance) {

}

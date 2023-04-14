#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "ResourceManager.h"
#include "FPSComponent.h"
#include "RotationComponent.h"
#include "LivesComponent.h"

#include "InputManager.h"
#include "Controller.h"
#include "Command.h"
#include "LivesObserverComponent.h"

void load()
{
	auto& resourceManager = dae::ResourceManager::GetInstance();
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& input = dae::InputManager::GetInstance();

	// Background
	auto goBackground = std::make_shared<dae::GameObject>();
	goBackground->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("background.tga"));
	scene.Add(goBackground);

	// Logo
	auto goLogo = std::make_shared<dae::GameObject>();
	goLogo->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("logo.tga"));
	goLogo->GetTransform().SetWorldPosition(216, 180, 0);
	scene.Add(goLogo);

	// Pivot point
	/*auto goPivotPoint = std::make_shared<dae::GameObject>();
	goPivotPoint->GetTransform().SetWorldPosition(310, 300, 0);
	scene.Add(goPivotPoint);*/

	// Pengo
	auto goPengo = std::make_shared<dae::GameObject>();
	goPengo->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("pengo.png"));
	goPengo->GetTransform().SetLocalPosition(50, 0, 0);
	goPengo->AddComponent<dae::LivesComponent>()->SetLives(3);
	scene.Add(goPengo);

	// SnoBee <- Pengo
	auto goSnoBee = std::make_shared<dae::GameObject>();
	goSnoBee->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("snobee.png"));
	goSnoBee->GetTransform().SetLocalPosition(20, 0, 0);
	goSnoBee->AddComponent<dae::LivesComponent>()->SetLives(3);
	scene.Add(goSnoBee);
	
	// Input
	// Controller
	/*input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadRight, dae::keyState::isDown, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{1, 0, 0}, 200.f));
	input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadLeft, dae::keyState::isDown, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{-1, 0, 0}, 200.f));
	input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadUp, dae::keyState::isDown,	  std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{0, -1, 0}, 200.f));
	input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadDown, dae::keyState::isDown,  std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{0, 1, 0}, 200.f));*/

	// Keyboard
	input.AddCommand(SDL_SCANCODE_UP, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ 0, -1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_LEFT, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ -1, 0, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_DOWN, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ 0, 1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_RIGHT, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ 1, 0, 0 }, 100.f));

	input.AddCommand(SDL_SCANCODE_W, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(), glm::vec3{ 0, -1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_A, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(), glm::vec3{ -1, 0, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_S, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(),  glm::vec3{ 0, 1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_D, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(),  glm::vec3{ 1, 0, 0 }, 100.f));

	
	// Text objects
	// Prog 4 Ass text
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto toProg4 = std::make_shared<dae::GameObject>();
	toProg4->AddComponent<dae::TextureComponent>();
	toProg4->AddComponent<dae::TextComponent>()->SetFont(font);
	toProg4->GetComponent<dae::TextComponent>()->SetText("Programming 4 Assignment");
	toProg4->GetTransform().SetWorldPosition(80, 20, 0);
	scene.Add(toProg4);

	// FPS
	auto toFPS = std::make_shared<dae::GameObject>();
	toFPS->AddComponent<dae::TextureComponent>();
	toFPS->AddComponent<dae::TextComponent>()->SetFont(font);
	toFPS->AddComponent<dae::FPSComponent>();
	scene.Add(toFPS);

	// Lives Display Pengo
	auto toLivesDisplayPengo = std::make_shared<dae::GameObject>();
	toLivesDisplayPengo->AddComponent<dae::TextureComponent>();
	toLivesDisplayPengo->GetTransform().SetLocalPosition(0, 50, 0);
	toLivesDisplayPengo->AddComponent<dae::TextComponent>()->SetFont(font);
	toLivesDisplayPengo->AddComponent<dae::LivesObserverComponent>()->SetLivesComponent(goPengo->GetComponent<dae::LivesComponent>());
	scene.Add(toLivesDisplayPengo);

	// Lives Display SnoBee
	auto toLivesDisplaySnoBee = std::make_shared<dae::GameObject>();
	toLivesDisplaySnoBee->AddComponent<dae::TextureComponent>();
	toLivesDisplaySnoBee->GetTransform().SetLocalPosition(0, 100, 0);
	toLivesDisplaySnoBee->AddComponent<dae::TextComponent>()->SetFont(font);
	toLivesDisplaySnoBee->AddComponent<dae::LivesObserverComponent>()->SetLivesComponent(goSnoBee->GetComponent<dae::LivesComponent>());
	scene.Add(toLivesDisplaySnoBee);

	// Observe Pengo Lives
	goPengo->GetComponent<dae::LivesComponent>()->AddObserver(toLivesDisplayPengo->GetComponent<dae::LivesObserverComponent>());
	// Observe SnoBee Lives
	goSnoBee->GetComponent<dae::LivesComponent>()->AddObserver(toLivesDisplaySnoBee->GetComponent<dae::LivesObserverComponent>());

	// Damage
	goPengo->GetComponent<dae::LivesComponent>()->LowerLives(2);
	goSnoBee->GetComponent<dae::LivesComponent>()->LowerLives();
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}
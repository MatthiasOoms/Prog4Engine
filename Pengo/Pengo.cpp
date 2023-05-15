#include <SDL.h>

// These things make sure the sign mismatch error isn't thrown in matchmakingtypes.h
#pragma warning(push)
#pragma warning(disable : 6340)
// Some include(s) with warnings
#pragma warning(pop)

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
#include "ScoreComponent.h"

#include "LivesObserverComponent.h"
#include "ScoreObserverComponent.h"

#include "InputManager.h"
#include "Controller.h"
#include "Command.h"
#include <iostream>
#include "KillCommand.h"
#include "ScoreCommand.h"

#include <SoundServiceLocator.h>
#include <SDLSoundSystem.h>
#include <LoggingSoundSystem.h>
#include <SDL_mixer.h>

void load()
{
#if _DEBUG
	dae::SoundServiceLocator::RegisterSoundSystem(
		std::make_unique<dae::LoggingSoundSystem>(std::make_unique<dae::SDLSoundSystem>())
	);
#else
	dae::SoundServiceLocator::RegisterSoundSystem(std::make_unique<dae::SDLSoundSystem>());
#endif
	auto& soundSystem = dae::SoundServiceLocator::GetSoundSystem();
	auto& resourceManager = dae::ResourceManager::GetInstance();
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& input = dae::InputManager::GetInstance();

	soundSystem.Load("../Data/Missile.wav");
	soundSystem.Play(0, 10);

	// Images
	// Background
	auto goBackground = std::make_shared<dae::GameObject>();
	goBackground->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("background.tga"));
	scene.Add(goBackground);

	// Logo
	auto goLogo = std::make_shared<dae::GameObject>();
	goLogo->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("logo.tga"));
	goLogo->GetTransform().SetWorldPosition(216, 180, 0);
	scene.Add(goLogo);

	// Game Objects

	// Pivot point
	/*auto goPivotPoint = std::make_shared<dae::GameObject>();
	goPivotPoint->GetTransform().SetWorldPosition(310, 300, 0);
	scene.Add(goPivotPoint);*/

	// Pengo
	auto goPengo = std::make_shared<dae::GameObject>();
	goPengo->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("pengo.png"));
	goPengo->GetTransform().SetLocalPosition(50, 0, 0);

	goPengo->AddComponent<dae::LivesComponent>()->SetLives(3);
	goPengo->AddComponent<dae::ScoreComponent>();

	scene.Add(goPengo);

	// SnoBee <- Pengo
	auto goSnoBee = std::make_shared<dae::GameObject>();
	goSnoBee->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("snobee.png"));
	goSnoBee->GetTransform().SetLocalPosition(20, 0, 0);

	goSnoBee->AddComponent<dae::LivesComponent>()->SetLives(3);
	goSnoBee->AddComponent<dae::ScoreComponent>();

	scene.Add(goSnoBee);

	// Input
	// Controller
	/*input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadRight, dae::keyState::isDown, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{1, 0, 0}, 200.f));
	input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadLeft, dae::keyState::isDown, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{-1, 0, 0}, 200.f));
	input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadUp, dae::keyState::isDown,	  std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{0, -1, 0}, 200.f));
	input.AddCommand(int(dae::Controller::ControllerIdx::First), dae::Controller::ControllerButton::DPadDown, dae::keyState::isDown,  std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{0, 1, 0}, 200.f));*/

	// Keyboard
	// Move
	input.AddCommand(SDL_SCANCODE_UP, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ 0, -1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_LEFT, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ -1, 0, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_DOWN, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ 0, 1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_RIGHT, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goPengo.get(), glm::vec3{ 1, 0, 0 }, 100.f));
	// Move
	input.AddCommand(SDL_SCANCODE_W, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(), glm::vec3{ 0, -1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_A, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(), glm::vec3{ -1, 0, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_S, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(), glm::vec3{ 0, 1, 0 }, 100.f));
	input.AddCommand(SDL_SCANCODE_D, dae::keyState::isPressed, std::make_unique<dae::MoveCommand>(goSnoBee.get(), glm::vec3{ 1, 0, 0 }, 100.f));
	// Kill
	input.AddCommand(SDL_SCANCODE_Z, dae::keyState::isDown, std::make_unique<dae::KillCommand>(goPengo.get()));
	input.AddCommand(SDL_SCANCODE_X, dae::keyState::isDown, std::make_unique<dae::KillCommand>(goSnoBee.get()));
	// Score
	input.AddCommand(SDL_SCANCODE_C, dae::keyState::isDown, std::make_unique<dae::ScoreCommand>(goPengo.get()));
	input.AddCommand(SDL_SCANCODE_V, dae::keyState::isDown, std::make_unique<dae::ScoreCommand>(goSnoBee.get()));

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
	toLivesDisplayPengo->GetTransform().SetLocalPosition(0, 100, 0);
	toLivesDisplayPengo->AddComponent<dae::TextComponent>()->SetFont(font);
	toLivesDisplayPengo->AddComponent<dae::LivesObserverComponent>();
	scene.Add(toLivesDisplayPengo);

	// Score Display Pengo
	auto toScoreDisplayPengo = std::make_shared<dae::GameObject>();
	toScoreDisplayPengo->AddComponent<dae::TextureComponent>();
	toScoreDisplayPengo->GetTransform().SetLocalPosition(0, 150, 0);
	toScoreDisplayPengo->AddComponent<dae::TextComponent>()->SetFont(font);
	toScoreDisplayPengo->AddComponent<dae::ScoreObserverComponent>();
	scene.Add(toScoreDisplayPengo);

	// Lives Display SnoBee
	auto toLivesDisplaySnoBee = std::make_shared<dae::GameObject>();
	toLivesDisplaySnoBee->AddComponent<dae::TextureComponent>();
	toLivesDisplaySnoBee->GetTransform().SetLocalPosition(0, 300, 0);
	toLivesDisplaySnoBee->AddComponent<dae::TextComponent>()->SetFont(font);
	toLivesDisplaySnoBee->AddComponent<dae::LivesObserverComponent>();
	scene.Add(toLivesDisplaySnoBee);

	// Score Display SnoBee
	auto toScoreDisplaySnoBee = std::make_shared<dae::GameObject>();
	toScoreDisplaySnoBee->AddComponent<dae::TextureComponent>();
	toScoreDisplaySnoBee->GetTransform().SetLocalPosition(0, 350, 0);
	toScoreDisplaySnoBee->AddComponent<dae::TextComponent>()->SetFont(font);
	toScoreDisplaySnoBee->AddComponent<dae::ScoreObserverComponent>();
	scene.Add(toScoreDisplaySnoBee);



	// Observers
	// Observe Pengo
	goPengo->GetComponent<dae::LivesComponent>()->AddObserver(toLivesDisplayPengo->GetComponent<dae::LivesObserverComponent>());
	goPengo->GetComponent<dae::ScoreComponent>()->AddObserver(toScoreDisplayPengo->GetComponent<dae::ScoreObserverComponent>());
	// Observe SnoBee
	goSnoBee->GetComponent<dae::LivesComponent>()->AddObserver(toLivesDisplaySnoBee->GetComponent<dae::LivesObserverComponent>());
	goSnoBee->GetComponent<dae::ScoreComponent>()->AddObserver(toScoreDisplaySnoBee->GetComponent<dae::ScoreObserverComponent>());


	// Events
	// Death
	goPengo->GetComponent<dae::LivesComponent>()->LowerLives(2);
	goSnoBee->GetComponent<dae::LivesComponent>()->LowerLives();

	// Score
	goPengo->GetComponent<dae::ScoreComponent>()->IncreaseScore(100);
	goSnoBee->GetComponent<dae::ScoreComponent>()->SetScore(50);



	// Text
	// Controls print
	auto toWASD = std::make_shared<dae::GameObject>();
	toWASD->AddComponent<dae::TextureComponent>();
	toWASD->GetTransform().SetLocalPosition(200, 250, 0);
	toWASD->AddComponent<dae::TextComponent>()->SetFont(font);
	toWASD->GetComponent<dae::TextComponent>()->SetText("WASD: Move");
	scene.Add(toWASD);

	auto toArrows = std::make_shared<dae::GameObject>();
	toArrows->AddComponent<dae::TextureComponent>();
	toArrows->GetTransform().SetLocalPosition(200, 300, 0);
	toArrows->AddComponent<dae::TextComponent>()->SetFont(font);
	toArrows->GetComponent<dae::TextComponent>()->SetText("ARROWS: Move");
	scene.Add(toArrows);

	auto toKill = std::make_shared<dae::GameObject>();
	toKill->AddComponent<dae::TextureComponent>();
	toKill->GetTransform().SetLocalPosition(200, 350, 0);
	toKill->AddComponent<dae::TextComponent>()->SetFont(font);
	toKill->GetComponent<dae::TextComponent>()->SetText("Z/X: Kill");
	scene.Add(toKill);

	auto toScore = std::make_shared<dae::GameObject>();
	toScore->AddComponent<dae::TextureComponent>();
	toScore->GetTransform().SetLocalPosition(200, 400, 0);
	toScore->AddComponent<dae::TextComponent>()->SetFont(font);
	toScore->GetComponent<dae::TextComponent>()->SetText("C/V: Score Up");
	scene.Add(toScore);

}

int main(int, char* [])
{
	dae::Minigin engine("../Data/");
	engine.Run(load);

	return 0;
}
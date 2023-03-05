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

void load()
{
	auto& resourceManager = dae::ResourceManager::GetInstance();
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	// Background
	auto goBackground = std::make_shared<dae::GameObject>();
	goBackground->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("background.tga"));
	scene.Add(goBackground);

	// Logo
	auto goLogo = std::make_shared<dae::GameObject>();
	goLogo->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("logo.tga"));
	goLogo->GetTransform().SetWorldPosition(216, 180, 0);
	scene.Add(goLogo);

	// Pengo
	auto goPengo = std::make_shared<dae::GameObject>();
	goPengo->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("pengo.png"));
	goPengo->GetTransform().SetWorldPosition(310, 300, 0);
	scene.Add(goPengo);

	// SnoBee <- Pengo
	auto goSnoBee = std::make_shared<dae::GameObject>(goPengo.get());
	goSnoBee->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("snobee.png"));
	goSnoBee->GetTransform().SetLocalPosition(50, 0, 0);
	scene.Add(goSnoBee);

	// Prog 4 Ass text
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::GameObject>();
	to->AddComponent<dae::TextureComponent>();
	to->AddComponent<dae::TextComponent>()->SetFont(font);
	to->GetComponent<dae::TextComponent>()->SetText("Programming 4 Assignment");
	to->GetTransform().SetWorldPosition(80, 20, 0);
	scene.Add(to);

	// FPS
	to = std::make_shared<dae::GameObject>();
	to->AddComponent<dae::TextureComponent>();
	to->AddComponent<dae::TextComponent>()->SetFont(font);
	to->AddComponent<dae::FPSComponent>();
	scene.Add(to);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}
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
	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("background.tga"));
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::TextureComponent>()->SetTexture(resourceManager.LoadTexture("logo.tga"));
	go->GetTransform().SetLocalPosition(216, 180, 0);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::GameObject>();
	to->AddComponent<dae::TextureComponent>();
	to->AddComponent<dae::TextComponent>()->SetFont(font);
	to->GetComponent<dae::TextComponent>()->SetText("Programming 4 Assignment");
	to->GetTransform().SetLocalPosition(80, 20, 0);
	scene.Add(to);

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
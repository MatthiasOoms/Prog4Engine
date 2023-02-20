#pragma once
#include "VisualComponent.h"
#include "Transform.h"
#include <string>
#include <memory>

class Font;
class Texture2D;
class TextComponent final : public VisualComponent
{
public:
	void Update(float deltaTime) override;
	void Render() const override;

	void SetText(const std::string& text);
	void SetPosition(float x, float y);

	TextComponent(const std::string& text, std::shared_ptr<Font> font);
	virtual ~TextComponent() = default;
	TextComponent(const TextComponent& other) = delete;
	TextComponent(TextComponent&& other) = delete;
	TextComponent& operator=(const TextComponent& other) = delete;
	TextComponent& operator=(TextComponent&& other) = delete;

private:
	bool m_needsUpdate;
	std::string m_text;
	dae::Transform m_transform{};
	std::shared_ptr<Font> m_font;
	std::shared_ptr<Texture2D> m_textTexture;
};


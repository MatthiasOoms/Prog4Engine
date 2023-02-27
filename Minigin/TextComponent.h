#pragma once
#include "Component.h"
#include <stdexcept>
#include <SDL_ttf.h>
#include <memory>
#include <string>
namespace dae 
{
	class GameObject;
	class Texture2D;
	class Transform;
	class Font;

	class TextComponent : public UpdateComponent
	{
	public:
		TextComponent() = default;
		virtual ~TextComponent() = default;

		virtual void Update(float, const GameObject* obj) override;

		void SetText(const std::string& text);
		void SetFont(const std::shared_ptr<Font>& font);

	private:
		bool m_NeedsUpdate;
		std::string m_Text;
		std::shared_ptr<Font> m_pFont;

		// Add ptr to GameObject in Interface classes
		// Now there's only access in Update and Render
	};
}

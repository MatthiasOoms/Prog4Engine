#pragma once
#include "Component.h"
#include <memory>

namespace dae
{
	class Texture2D;
	class GameObject;

	class TextureComponent : public RenderComponent
	{
	public:
		TextureComponent(GameObject* pOwner);
		virtual ~TextureComponent();

		void SetTexture(const std::shared_ptr<Texture2D>& texture);
		virtual void Render(float elapsedSec, const GameObject* obj) const override;

	private:
		std::shared_ptr<Texture2D> m_pTexture;
	};
};


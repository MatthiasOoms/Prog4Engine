#include "ScoreComponent.h"
#include "GameObject.h"
#include "Observer.h"
#include "Subject.h"

dae::ScoreComponent::ScoreComponent(GameObject* pOwner)
	: Component{ pOwner }
	, m_Score{}
{
	m_pSubject = new Subject{};
}

dae::ScoreComponent::~ScoreComponent()
{
	delete m_pSubject;
	m_pSubject = nullptr;
}

void dae::ScoreComponent::IncreaseScore(int amount)
{
	m_Score += amount;
}

void dae::ScoreComponent::SetScore(int score)
{
	m_Score = score;
}

void dae::ScoreComponent::AddObserver(Observer* pObserver)
{
	m_pSubject->addObserver(pObserver);
}

int dae::ScoreComponent::GetScore() const
{
	return m_Score;
}

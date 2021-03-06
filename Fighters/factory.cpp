#include "factory.h"
#include "fighterinputdriver.h"
#include "fighteraidriver.h"

std::shared_ptr<Fighter> Factory::createPlayerFighter(Vector2 position, Vector2 size, double speed)
{
	std::shared_ptr<Fighter> fighter = std::make_shared<Fighter>(position, size, speed);
	fighter->driver = std::make_unique<FighterInputDriver>(*fighter);

	return fighter;
}

std::shared_ptr<Fighter> Factory::createAIFighter(Vector2 position, Vector2 size, double speed, Fighter& target)
{
	std::shared_ptr<Fighter> fighter = std::make_shared<Fighter>(position, size, speed);
	fighter->driver = std::make_unique<FighterAIDriver>(*fighter, target);

	return fighter;
}
#include <VictoryPointCard.hpp>

VictoryPointCard::VictoryPointCard(QString& title, QString& flavor_text) :
	title(title),
	flavor_text(flavor_text)
{
	
}

const QString& VictoryPointCard::getTitle() const
{
	return title;
}

const QString& VictoryPointCard::getFlavorText() const
{
	return flavor_text;
}
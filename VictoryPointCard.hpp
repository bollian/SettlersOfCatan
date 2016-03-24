#ifndef SETTLERS_OF_CATAN_VICTORYPOINTCARD_H_
#define SETTLERS_OF_CATAN_VICTORYPOINTCARD_H_

#include <QtCore/QString>

class VictoryPointCard 
{
public:
	VictoryPointCard(QString& title, QString& flavor_text);
	
	const QString& getTitle() const;
	const QString& getFlavorText() const;
	
private:
	QString title;
	QString flavor_text;
	
};

#endif // SETTLERS_OF_CATAN_VICTORYPOINTCARD_H_
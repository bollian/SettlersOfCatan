#ifndef SETTLERS_OF_CATAN_SPINNERANDSLIDER_H_
#define SETTLERS_OF_CATAN_SPINNERANDSLIDER_H_

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

class SpinnerAndSlider : public QWidget
{
	Q_OBJECT
public:
	SpinnerAndSlider(int max, int min = 0, int interval = 1, QWidget* parent = NULL);
	
	int getValue() const;
	
	void setMin(int min);
	void setMax(int max);
	void setInterval(int interval);
	
	int getMin() const;
	int getMax() const;
	int getInterval() const;

private:
	QHBoxLayout layout;
	QSlider slider;	
	QSpinBox spin_box;
};

#endif // SETTLERS_OF_CATAN_SPINNERANDSLIDER_H_

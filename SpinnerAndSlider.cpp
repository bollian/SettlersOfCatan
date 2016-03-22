#include <iostream>

#include <Qt>
#include <QtCore/QObject>

#include <SpinnerAndSlider.hpp>

using namespace std;

SpinnerAndSlider::SpinnerAndSlider(int max, int min, int interval, QWidget* parent) : QWidget(parent),
	layout(),
	slider(Qt::Horizontal),	
	spin_box()
{
	setMax(max);
	setMin(min);
	setInterval(interval);
	
	slider.setTickPosition(QSlider::TicksBelow);
	
	connect(&spin_box, (void (QSpinBox::*)(int))(&QSpinBox::valueChanged), &slider, &QSlider::setValue);
	connect(&slider, &QSlider::valueChanged, &spin_box, &QSpinBox::setValue);
	
	layout.addWidget(&spin_box);
	layout.addWidget(&slider);
	
	setLayout(&layout);
}

int SpinnerAndSlider::getValue() const
{
	return spin_box.value();
}

void SpinnerAndSlider::setMax(int max)
{
	spin_box.setMaximum(max);
	slider.setMaximum(max);
}

void SpinnerAndSlider::setMin(int min)
{
	spin_box.setMinimum(min);
	slider.setMinimum(min);
}

void SpinnerAndSlider::setInterval(int interval)
{
	spin_box.setSingleStep(interval);
	slider.setTickInterval(interval);
}

int SpinnerAndSlider::getMax() const
{
	return spin_box.maximum();
}

int SpinnerAndSlider::getMin() const
{
	return spin_box.minimum();
}

int SpinnerAndSlider::getInterval() const
{
	return spin_box.singleStep();
}
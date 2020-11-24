#ifndef RCJSIM_MOCKUP_SENSOR_H
#define RCJSIM_MOCKUP_SENSOR_H

class Robot;
class World;

class Sensor
{
protected:
	const Robot& robot;

public:
	Sensor(const Robot& robot);
	virtual ~Sensor();
	virtual void update(const World& state) = 0;
};

class SimpleBallDirectionSensor:
	public Sensor
{
private:
	float reading;

public:
	using Sensor::Sensor;
	const float getReading() const;
	virtual void update(const World& state) override;
};

#endif // RCJSIM_MOCKUP_SENSOR_H

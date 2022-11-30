#pragma once
class GameNode
{
public:
	GameNode();
	virtual ~GameNode() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual HBRUSH getBrush() = 0;

	//getter
	const POINT& getPoint() { return point; }
	const RECT& getRect() { return rect; }
	const int& getInterval() { return interval; }
	//setter
	void setPoint(POINT point) { this->point = point; }
	void setRect(RECT rect) { this->rect = rect; }

protected:
	POINT point;
	RECT rect;
	int interval;
};


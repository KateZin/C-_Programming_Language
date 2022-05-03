#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.hpp"


using namespace std;
using namespace sf;

constexpr float carriageWidth{80.f}, carriageHeight{20.f}, carriageVelocity{8.f};

class Carriage {
public:
	RectangleShape shape;
	Vector2f velocity;
	float getX() { return shape.getPosition().x; };
	float getY() { return shape.getPosition().y; };
	float left() { return getX() - shape.getSize().x / 2.f; }
	float right() { return getX() + shape.getSize().x / 2.f; }
	float top() { return getY() - shape.getSize().y / 2.f; }
	float bottom() { return getY() + shape.getSize().y / 2.f; }

	Carriage(float _x, float _y) {
		shape.setPosition(_x, _y);
		shape.setFillColor(Color::Red);
		shape.setSize({ carriageWidth, carriageHeight });
		shape.setOrigin(carriageWidth/2.f, carriageHeight/2.f);
	}
	void update() {
		shape.move(velocity);
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0) {
			velocity.x = -carriageVelocity;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth) {
			velocity.x = carriageVelocity;
		}
		else {
			velocity.x = 0;
		}
	}
};
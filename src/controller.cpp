#include "../include/controller.h"

controller::controller(camera* _p_camera, window* _p_window)
{
	forward = sf::Keyboard::Z;
	backward = sf::Keyboard::S;
	right = sf::Keyboard::D;
	left = sf::Keyboard::Q;
	up = sf::Keyboard::Space;
	down = sf::Keyboard::LShift;
	moving = false;
	move_active = true;
	p_camera = _p_camera;
	p_window = _p_window;
}

controller::controller(const sf::Keyboard::Key& _forward, const sf::Keyboard::Key& _backward, const sf::Keyboard::Key& _right, const sf::Keyboard::Key& _left, const sf::Keyboard::Key& _up, const sf::Keyboard::Key& _down)
{
	forward = _forward;
	backward = _backward;
	right = _right;
	left = _left;
	up = _up;
	down = _down;
}

void controller::move()
{
	if (sf::Keyboard::isKeyPressed(forward))
		p_camera->position += p_camera->w;
	if (sf::Keyboard::isKeyPressed(backward))
		p_camera->position += -p_camera->w;
	if (sf::Keyboard::isKeyPressed(right))
		p_camera->position += -p_camera->u;
	if (sf::Keyboard::isKeyPressed(left))
		p_camera->position += p_camera->u;
	if (sf::Keyboard::isKeyPressed(up))
		p_camera->position += p_camera->v;
	if (sf::Keyboard::isKeyPressed(down))
		p_camera->position += -p_camera->v;
}

void controller::check_event(const sf::Event& event)
{
	if (move_active)
	{
		if (!moving && event.type == sf::Event::MouseButtonReleased && p_window->is_in(sf::Mouse::getPosition(*p_window->get_window())))
			moving = true;
		if (moving && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			moving = false;
	}
}

void controller::update()
{
	if (move_active && moving)
	{
		if (move_active)
			move();
	}
}

controller& controller::change_camera(camera* my_camera)
{
	p_camera = my_camera;
	return *this;
}

controller& controller::change_window(window* my_window)
{
	p_window = my_window;
	return *this;
}
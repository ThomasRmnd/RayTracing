#pragma once

#include <SFML/Graphics.hpp>

#include "controller.h"
#include "render.h"

class controller;
class render;

class window
{
private:
	sf::Image* p_image;
	sf::Texture* p_texture;
	sf::Sprite* p_sprite;
	sf::RenderWindow* p_rwindow;
	render* p_render;
	controller* p_controller;

public:
	window(sf::RenderWindow&, render&, controller&);
	~window();

	void create(sf::VideoMode, const std::string&);
	bool isOpen() const;
	void check_events(const sf::Event& event);
	void update();
	bool pollEvent(sf::Event& event);
	void close();

	bool is_in(const sf::Vector2i&);
	sf::RenderWindow* get_window();
};

sf::RenderWindow& get_window();
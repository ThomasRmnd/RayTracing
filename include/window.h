#pragma once

#include <SFML/Graphics.hpp>

#include "render.h"

class render;

class window
{
private:
	sf::Image* p_image;
	sf::Texture* p_texture;
	sf::Sprite* p_sprite;
	sf::RenderWindow* p_rwindow;
	render* p_render;

public:
	window(sf::RenderWindow&, render&);
	~window();

	void create(sf::VideoMode, const std::string&);
	bool isOpen() const;
	void update();
	bool pollEvent(sf::Event& event);
	void close();
};
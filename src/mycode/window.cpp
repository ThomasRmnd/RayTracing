#include "../../include/window.h"

window::window(sf::RenderWindow& _p_rwindow, render& _p_render)
{
	p_render = &_p_render;
	p_rwindow = &_p_rwindow;
	p_image = new sf::Image();
	p_image->create(p_render->p_ecran->get_nb_col(), p_render->p_ecran->get_nb_row());
	p_texture = new sf::Texture();
	p_texture->loadFromImage(*p_image);
	p_sprite = new sf::Sprite();
	p_sprite->setTexture(*p_texture);
}

window::~window()
{
	delete p_image;
	delete p_texture;
	delete p_sprite;
}

void window::create(sf::VideoMode mode, const std::string& title)
{
	p_rwindow->create(mode, title);
}

bool window::isOpen() const
{
	return p_rwindow->isOpen();
}

void window::update()
{
	p_render->lancer4(3, 3);
	unsigned int n_x = p_render->p_ecran->get_nb_col();
	unsigned int n_y = p_render->p_ecran->get_nb_row();
	for (unsigned int i = 0; i < n_x; i++)
	{
		for (unsigned int j = 0; j < n_y; j++)
		{
			vector3 value = p_render->p_ecran->at(j, i);
			p_image->setPixel(i, j, sf::Color((int)value.x, (int)value.y, (int)value.z));
		}
	}
	p_texture->update(*p_image);
	p_sprite->setTexture(*p_texture);
	p_rwindow->draw(*p_sprite);
	p_rwindow->display();
}

bool window::pollEvent(sf::Event& event)
{
	return p_rwindow->pollEvent(event);
}

void window::close()
{
	p_rwindow->close();
}
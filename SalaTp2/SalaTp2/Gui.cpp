#include"Gui.h"
Gui::Gui(){
	n = 3;
	initialLife = n;
}
void Gui::Initialize() {
	if (!fontLife.loadFromFile("assets/foo.ttf")) {
		std::cout << "error font";
	}
	textLife.setFont(fontLife);
	numLife.setFont(fontLife);
	texPlanes.setFont(fontLife);
	numPlanes.setFont(fontLife);
	textTarget.setFont(fontLife);
	numTarget.setFont(fontLife);

	textLife.setString("LIFES: ");
	numLife.setString(std::to_string(n));
	texPlanes.setString("PLANES: ");
	numPlanes.setString("0");
	textTarget.setString("TARGET: ");
	numTarget.setString(std::to_string(initialTarget));

	textLife.setCharacterSize(24);
	numLife.setCharacterSize(24);
	texPlanes.setCharacterSize(24);
	numPlanes.setCharacterSize(24);
	textTarget.setCharacterSize(24);
	numTarget.setCharacterSize(24);

	numLife.setPosition(70, 0);
	texPlanes.setPosition(800-texPlanes.getLocalBounds().width-numPlanes.getLocalBounds().width-10, 0);
	numPlanes.setPosition(texPlanes.getPosition().x+texPlanes.getLocalBounds().width,0);
	textTarget.setPosition(400 - textTarget.getLocalBounds().width/2, 0);
	numTarget.setPosition(textTarget.getPosition().x + textTarget.getLocalBounds().width + 10, 0);
	
}
void Gui::Draw(){
	window->draw(textLife);
	window->draw(numLife);
	window->draw(texPlanes);
	window->draw(numPlanes);
	window->draw(textTarget);
	window->draw(numTarget);
}
void Gui::ChangeLife(){
	n--;
	numLife.setString(std::to_string(n));
}
void Gui::ChangePlanes(){
	num_Planes++;
	numPlanes.setString(std::to_string(num_Planes));
}
void Gui::ResetLife() {
	numLife.setString(std::to_string(n));
}
void Gui::ResetPlanes(){
	numPlanes.setString(std::to_string(num_Planes));
}



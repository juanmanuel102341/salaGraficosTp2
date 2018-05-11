#include"Menu.h"

void Menu::Draw(){
	window->draw(spriteBack);
	if (win) {
		window->draw(textWin);
	}
	else {
		window->draw(textLoose);
	}
	window->draw(spriteExit);
	window->draw(spriteRestart);
}
void Menu::HandleMouseEvent(int x,int y){

	std::cout << "mouse x" << x;
	std::cout << "mouse y" << y;
	if (x > spriteRestart.getPosition().x&&x < spriteRestart.getPosition().x+spriteRestart.getLocalBounds().width&&y>spriteRestart.getPosition().y&&y < spriteRestart.getPosition().y + spriteRestart.getLocalBounds().height) {

		std::cout << "contacto boton restart!!" <<std::endl;
		res = Result::restart;
		myFinish=true;
	}
	if (x > spriteExit.getPosition().x&&x < spriteExit.getPosition().x + spriteExit.getLocalBounds().width&&y>spriteExit.getPosition().y&&y < spriteExit.getPosition().y + spriteExit.getLocalBounds().height) {

		std::cout << "contacto boton exit!!" << std::endl;
		res = Result::exit;
		myFinish = true;
	}
}
bool Menu::Finish(){
	if (myFinish) {
		return true;
	}
	return false;
}
void Menu::Init(){
	if (!textureBack.loadFromFile("assets/menuBack.png")) {
		std::cout << "error";
	};
	if (!textureRestart.loadFromFile("assets/menuRestart.png")) {
		std::cout << "error";
	};
	if (!textureExit.loadFromFile("assets/menuExit.png")) {
		std::cout << "error";
	};
	if (!fontFinal.loadFromFile("assets/foo.ttf")) {
		std::cout << "error font";
	}
	textWin.setFont(fontFinal);
	textLoose.setFont(fontFinal);

	textWin.setFillColor(sf::Color::Green);
	textLoose.setFillColor(sf::Color::Red);

	textWin.setCharacterSize(45);
	textLoose.setCharacterSize(45);

	textWin.setString("YOU WIN!");
	textLoose.setString("YOU LOOSE!");

	spriteBack.setTexture(textureBack);
	spriteRestart.setTexture(textureRestart);
	spriteExit.setTexture(textureExit);

	spriteBack.setPosition(400 - spriteBack.getLocalBounds().width / 2, 300 - spriteBack.getLocalBounds().height / 2);
	spriteExit.setPosition(spriteBack.getPosition().x + 30, spriteBack.getPosition().y + spriteBack.getLocalBounds().height -spriteExit.getLocalBounds().height-30);
	spriteRestart.setPosition(spriteBack.getPosition().x + spriteBack.getLocalBounds().width - spriteRestart.getLocalBounds().width  - 30, spriteBack.getPosition().y + spriteBack.getLocalBounds().height -spriteRestart.getLocalBounds().height-30);

	textWin.setPosition(spriteBack.getPosition().x + spriteBack.getLocalBounds().width / 2-textWin.getLocalBounds().width/2, spriteBack.getPosition().y+ textWin.getLocalBounds().height);
	textLoose.setPosition(spriteBack.getPosition().x + spriteBack.getLocalBounds().width / 2- textLoose.getLocalBounds().width/2, spriteBack.getPosition().y+ textLoose.getLocalBounds().height);

}

Menu::Menu(sf::RenderWindow* _window){
	window = _window;
	

}
#include "oxygine-framework.h"
#include <functional>

using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations.
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;


class MainActor : public Actor
{
public:
	spTextField _text;

	MainActor()
	{
		spTextField text = new TextField();

		TextStyle style = TextStyle(gameResources.getResFont("main")).withColor(Color::Aqua);
		text->setPosition(500, 600);
		text->setStyle(style);
		text->setText("Hello World!");
		_text = text;
		addChild(_text);
	}

};
//declare spMainActor as intrusive_ptr holder of MainActor
typedef oxygine::intrusive_ptr<MainActor> spMainActor;
//you could use DECLARE_SMART preprocessor definition it does the same:
//DECLARE_SMART(MainActor, spMainActor)

void example_preinit() {}

//called from main.cpp
void example_init()
{
    gameResources.loadXML("res.xml");

    spMainActor actor = new MainActor;

    getStage()->addChild(actor);
}


//called each frame from main.cpp
void example_update()
{
}

//called each frame from main.cpp
void example_destroy()
{
    gameResources.free();
}

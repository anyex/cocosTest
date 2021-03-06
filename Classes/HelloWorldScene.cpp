#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //auto rootNode = CSLoader::createNode("MainScene.csb");

  //  addChild(rootNode);
	Sprite* beauty = (Sprite*)Sprite::create("beauty.png");
	beauty->setAnchorPoint(Vec2(0, 0));
	beauty->setPosition(Vec2(200,100));
	beauty->setScale(0.2);
	
	//beauty->setRotation(40.0f);//旋转
	//beauty->setSkewX(45);
	//beauty->setSkewY(30);


	addChild(beauty);

	//创建精灵
	/*auto _beauty = Sprite::create("beauty.png", Rect(0, 0, 140, 140));
	_beauty->setPosition(400, 400);
	addChild(_beauty);*/

	//动作
	 //旋转
	auto rotateBy = RotateBy::create(2,20);
	auto rotateTo = RotateTo::create(2, 20);
	beauty->runAction(rotateTo);
	 //缩放
	auto scaleBy = ScaleBy::create(2.0f, 3.0f);//将当前尺寸放大3倍
	auto scaleTo = ScaleTo::create(2.0f,0.5f);//放大当前比例到0.5,如果已经通过setScale设置为0.5将不会放大
	beauty->runAction(scaleTo);
    return true;
}

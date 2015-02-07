//
//  MenuTopScene.cpp
//  Menu
//
//  Created by MAEDAHAJIME on 2015/02/04.
//
//

#include "MenuTopScene.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

Scene* MenuTopScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = MenuTopScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool MenuTopScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    // ラベルを生成
    Label* label1 = Label::createWithSystemFont("Cocos2d-x", "Arial", 120);
    
    // ラベルの設置
    label1->setPosition(Point(winSize.width /2 ,winSize.height/1.5));
    
    // ラベルタイトルを追加
    this->addChild(label1,1);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    //Ver3.x CC_CALLBACK_1 （引数が１つ）にすること
    auto labelBtnLabel01 = LabelTTF::create("ラベルボタン０１", "Arial", 48);
    auto labelItem01 = MenuItemLabel::create(labelBtnLabel01, CC_CALLBACK_1(MenuTopScene::menuAction01, this));
    auto labelBtnLabel02 = LabelTTF::create("ラベルボタン０２", "Arial", 48);
    auto labelItem02 = MenuItemLabel::create(labelBtnLabel02, CC_CALLBACK_1(MenuTopScene::menuAction02, this));
    
    labelItem01->setPosition(Point(winSize.width / 2,winSize.height / 7.2));
    labelItem02->setPosition(Point(winSize.width / 2,winSize.height / 14.5));
    
    //後は同じ
    auto menu01 = Menu::create(labelItem01,labelItem02,NULL);
    
    menu01->setPosition(Point::ZERO);
    // メニューを追加
    this->addChild(menu01, 1);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    // ボタンを押した時にメソッドを呼び出す .h = void pushStart01(Ref *pSender); 宣言必要
    // pushStart01(メソッド) CC_CALLBACK_1（引数が１つ）にすること
    auto startButton01 = MenuItemImage::create(
                                        "menu-image1.png",  // 通常状態の画像
                                        "menu-image1-hover.png",  // 押下状態の画像
                 CC_CALLBACK_1(MenuTopScene::pushStart01, this)); // 押下時のアクション
    
    // ボタンを押した時にメソッドを呼び出す .h = void pushStart02(Ref *pSender); 宣言必要
    // pushStart02(メソッド)
    auto startButton02 = MenuItemImage::create(
                                        "menu-image2.png",  // 通常状態の画像
                                        "menu-image2-hover.png",  // 押下状態の画像
                 CC_CALLBACK_1(MenuTopScene::pushStart02, this)); // 押下時のアクション
    
    //ボタンを押した時にラムダ式(init内部記述式)を呼び出す
    auto startButton03 = MenuItemImage::
                    create("menu-image3.png","menu-image3-hover.png",[](Ref*sender){
        
        CCLOG("Pushボタン03");
        
    });
    
    // ボタンの設置
    startButton01->setPosition(Point(winSize.width / 2,winSize.height / 2.1));
    startButton02->setPosition(Point(winSize.width / 2,winSize.height / 2.8));
    startButton03->setPosition(Point(winSize.width / 2,winSize.height / 4.2));
    
    // メニューを作成 自動解放オブジェクト
    auto menu = Menu::create(startButton01,startButton02,startButton03,NULL);
    
    menu->setPosition(Point::ZERO);
    // メニューを追加
    this->addChild(menu, 1);
    
    
    return true;
}

// pushStart01ボタン
void MenuTopScene::pushStart01(Ref *pSender)
{
    CCLOG("Pushボタン01");
    
}

// pushStart02ボタン
void MenuTopScene::pushStart02(Ref *pSender)
{
    CCLOG("Pushボタン02");
    
}

// menuAction01ボタン
void MenuTopScene::menuAction01(Ref *pSender)
{
    CCLOG("ラベルボタン01");
    
}

// menuAction02ボタン
void MenuTopScene::menuAction02(Ref *pSender)
{
    CCLOG("ラベルボタン02");
    
}


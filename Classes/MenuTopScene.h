//
//  MenuTopScene.h
//  Menu
//
//  Created by MAEDAHAJIME on 2015/02/04.
//
//

#ifndef __Menu__MenuTopScene__
#define __Menu__MenuTopScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class MenuTopScene : public Layer
{
    
public:
    
    // 初期化のメソッド
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushStart01(Ref *pSender);
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushStart02(Ref *pSender);
    
    // テキストスタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void menuAction01(Ref *pSender);
    // テキストスタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void menuAction02(Ref *pSender);

    // create()を使えるようにしている。
    CREATE_FUNC(MenuTopScene);
};

#endif /* defined(__Menu__MenuTopScene__) */

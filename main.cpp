#define CAC_PROJ_NAME "GD Traveler"

#include "win32cac.h"
#include "config.h"
#include <fcntl.h>
#include <io.h>
#include <fstream>


#ifndef _USE_OLD_IOSTREAMS
using namespace std;
#endif

uint16_t config_length = 0;

#define OFFSET_USER_PROFILE_BUTTON 0x0802D388

int config_data_parsed;
char config_data[8];

const char version_lookup_table[4][4] = {
	"2.1",
	"2.0",
	"1.9",
	"1.8"
};

class $implement(MenuLayer, MyMenuLayer) {
 public:
	static inline bool (__thiscall* _init)(MenuLayer* self);

	void buttonCallback(CCObject* sender) {
		auto alert = FLAlertLayer::create(NULL, "Ooops", "Ok", NULL, "This feature is <cr>not supported</c> by gd-traveler.");
		alert->show();
	}

	bool inithook() {
		if (!_init(this)) return false;


		CCLabelTTF* gd_traveler_text = CCLabelTTF::create(TRAVELER_MAIN_INFO, "chatFont-uhd", 32.f);
		gd_traveler_text->setPositionX(533.f);
		gd_traveler_text->setPositionY(307.f);
		gd_traveler_text->setOpacity(50);
		gd_traveler_text->setScale(.25f);
		addChild(gd_traveler_text);

		auto base = reinterpret_cast<uintptr_t>(this);
		char buffer[1024];
		sprintf_s(buffer, "Using %s (%d)", version_lookup_table[config_data_parsed], config_data_parsed);

		CCLabelTTF* debug0 = CCLabelTTF::create(buffer, "chatFont-uhd", 32.f);
		debug0->setPositionX(533.f);
		debug0->setPositionY(296.f);
		debug0->setOpacity(50);
		debug0->setScale(.25f);
		addChild(debug0);

		if (config_data_parsed == 2) {
			CCObject* pObj = nullptr;

			CCARRAY_FOREACH(getChildren(), pObj) {
				CCNode* interaction0 = (CCNode*)pObj;
				CCPoint xy = interaction0->getPosition();

				if (xy.x == 284.5f && xy.y == 170.0f) {
					//[1] cocos2d::CCMenu {4}
					CCMenu* interaction1 = (CCMenu*)pObj;
					CCObject* pObj1 = nullptr;
					CCARRAY_FOREACH(interaction1->getChildren(), pObj1) {
						CCMenuItemSpriteExtra* interaction2 = (CCMenuItemSpriteExtra*)pObj1;
						CCPoint xy2 = interaction2->getPosition();
						if (xy2.x == -239.5f && xy2.y == -65.0f) interaction2->removeMeAndCleanup();
					}
				}
				if (xy.x == 47.0f && xy.y == 141.0f) {
					//[8] cocos2d::CCLabelBMFont {12}
					interaction0->removeMeAndCleanup();
				}
				if (xy.x == 284.5f && xy.y == 45.0f) {
					//[2] cocos2d::CCMenu {5}
					CCMenu* interaction1 = (CCMenu*)pObj;
					CCObject* pObj1 = nullptr;
					CCARRAY_FOREACH(interaction1->getChildren(), pObj1) {
						CCMenuItemSpriteExtra* interaction2 = (CCMenuItemSpriteExtra*)pObj1;
						CCPoint xy2 = interaction2->getPosition();
						if (xy2.x == 83.5f && xy2.y == 0.0f) interaction2->removeMeAndCleanup();
						if (xy2.x == 244.5f && xy2.y == 135.0f) interaction2->removeMeAndCleanup();
					}

					CCPoint ccp;
					ccp.x = 312;
					ccp.y = 45;
					interaction0->setPosition(ccp);
				}
			}
		}
		else if (config_data_parsed == 3) {
			CCObject* pObj = nullptr;

			CCARRAY_FOREACH(getChildren(), pObj) {
				CCNode* interaction0 = (CCNode*)pObj;
				CCPoint xy = interaction0->getPosition();

				if (xy.x == 284.5f && xy.y == 170.0f) {
					//[1] cocos2d::CCMenu {4}
					CCMenu* interaction1 = (CCMenu*)pObj;
					CCObject* pObj1 = nullptr;
					CCARRAY_FOREACH(interaction1->getChildren(), pObj1) {
						CCMenuItemSpriteExtra* interaction2 = (CCMenuItemSpriteExtra*)pObj1;
						CCPoint xy2 = interaction2->getPosition();
						if (xy2.x == -239.5f && xy2.y == -65.0f) interaction2->removeMeAndCleanup();
					}
				}
				if (xy.x == 47.0f && xy.y == 141.0f) {
					//[8] cocos2d::CCLabelBMFont {12}
					interaction0->removeMeAndCleanup();
				}
				if (xy.x == 284.5f && xy.y == 45.0f) {
					//[2] cocos2d::CCMenu {5}
					CCMenu* interaction1 = (CCMenu*)pObj;
					CCObject* pObj1 = nullptr;
					CCARRAY_FOREACH(interaction1->getChildren(), pObj1) {
						CCMenuItemSpriteExtra* interaction2 = (CCMenuItemSpriteExtra*)pObj1;
						CCPoint xy2 = interaction2->getPosition();
						
						if (xy2.x == 83.5f && xy2.y == 0.0f) {
							CCSprite* google_plus_button = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png");
							CCMenuItemSpriteExtra* google_plus_button0 = CCMenuItemSpriteExtra::create(
								google_plus_button,
								this,
								menu_selector(MyMenuLayer::buttonCallback)
							);
							interaction2->removeMeAndCleanup();
							google_plus_button0->setPosition(ccp(-85.5f - 56, 0.0f));
							interaction1->addChild(google_plus_button0);
						} 
						if (xy2.x == 244.5f && xy2.y == 135.0f) interaction2->removeMeAndCleanup();
						
						interaction2->setPositionX(interaction2->getPositionX() + 56);
						
					}

					//CCPoint ccp;
					//ccp.x = 312;
					//ccp.y = 45;
					//interaction0->setPosition(ccp);
				}
				if (xy.x == 50.0f && xy.y == 24.0f) {
					//[6] cocos2d::CCMenu {4}
					CCMenu* interaction1 = (CCMenu*)pObj;
					CCObject* pObj1 = nullptr;
					CCARRAY_FOREACH(interaction1->getChildren(), pObj1) {
						CCMenuItemSpriteExtra* interaction2 = (CCMenuItemSpriteExtra*)pObj1;
						CCPoint xy2 = interaction2->getPosition();
						if (xy2.x == 32.0f && xy2.y == 31.0f) {
							interaction2->removeMeAndCleanup();
						}
						if (xy2.x == -28.0f && xy2.y == 31.0f) {
							interaction2->setPosition(ccp(-21.0f, 36.0f));
							interaction2->setScale(1.25f);
						}
						if (xy2.x == 2.0f && xy2.y == 31.0f) {
							interaction2->setPosition(ccp(19.0f, 36.0f));
							interaction2->setScale(1.25f);
						}
					}
				}
			}
		}
		return true;
	}
};

void inject() {
	#if _WIN32
		auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

		MH_CreateHook(
			reinterpret_cast<void*>(base + 0x1907b0),
			reinterpret_cast<void*>(extract(&MyMenuLayer::inithook)),
			reinterpret_cast<void**>(&MyMenuLayer::_init));

		MH_EnableHook(MH_ALL_HOOKS);

		uint8_t avaliable = 0;
		FILE* fc; 
		fopen_s(&fc, "traveler.txt", "r");

		fgets(config_data, 8, fc);
		switch (config_data[0]){
			case '0': {
				config_data_parsed = 0;
				break;
			}
			case '1': {
				config_data_parsed = 1;
				break;
			}
			case '2': {
				config_data_parsed = 2;
				break;
			}
			case '3': {
				config_data_parsed = 3;
				break;
			}
			default:
				config_data_parsed = 0;
				break;
		}

		fclose(fc);
	
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif

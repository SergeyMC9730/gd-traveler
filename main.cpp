#define CAC_PROJ_NAME "GD Traveler"

#include "win32cac.h"
#include "config.h"
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include "cJSON/cJSON.h"


#ifndef _USE_OLD_IOSTREAMS
using namespace std;
#endif

CONSOLE_SCREEN_BUFFER_INFO coninfo;

#define OFFSET_USER_PROFILE_BUTTON 0x0802D388

cJSON* config_data_parsed;

const char version_lookup_table[4][4] = {
	"2.1",
	"1.9",
	"1.8"
};

class $implement(MenuLayer, MyMenuLayer) {
 public:
	static inline bool (__thiscall* _init)(MenuLayer* self);

	void buttonCallback(CCObject* sender) {
		auto alert = FLAlertLayer::create(NULL, "Mod", "Ok", NULL, "<cg>custom button!</c>");
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
		sprintf(buffer, "Using %s", version_lookup_table[cJSON_GetObjectItem(config_data_parsed, "current_ver")->valueint]);

		CCLabelTTF* debug0 = CCLabelTTF::create(buffer, "chatFont-uhd", 32.f);
		debug0->setPositionX(533.f);
		debug0->setPositionY(296.f);
		debug0->setOpacity(50);
		debug0->setScale(.25f);
		addChild(debug0);

		if (cJSON_GetObjectItem(config_data_parsed, "current_ver")->valueint == 2) {
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

		//auto sprite = CCSprite::create("dialogIcon_017.png");
		//auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_stopEditorBtn_001.png");

		//sprite->setPosition({100, 100});
		//sprite->setScale(0.5f);

		//addChild(sprite);

		//auto button = CCMenuItemSpriteExtra::create(
		    //buttonSprite,
		    //this,
		    //menu_selector(MyMenuLayer::buttonCallback));

		//auto menu = CCMenu::create();
		//menu->addChild(button);
		//menu->setPosition(ccp(150, 100));

		//addChild(menu);
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

	if (_access("traveler.json", 0)) avaliable = 1;

	FILE* fc = fopen("traveler.json", "w+");
	if (!avaliable) {
		int i = 0;
		const char config_data[] = "{\"enable\": true, \"current_ver\": 0}";
		fputs(config_data, fc);
		config_data_parsed = cJSON_Parse(config_data);
	}
	else {
		void *cfg = malloc(512);
		char* config_data = (char*)cfg;
		fgets(config_data, 512, fc);
		if (strlen(config_data) == 0) {
			free(cfg);
			char config_data2[] = "{\"enable\": true, \"current_ver\": 0}";
			fputs(config_data2, fc);
			config_data_parsed = cJSON_Parse(config_data2);
		}
		else {
			config_data_parsed = cJSON_Parse(config_data);
			free(cfg);
		}
	}

	fclose(fc);

	avaliable = 0;
	if (_access("traveler.json", 0)) avaliable = 1;
	fc = fopen("traveler.json", "w+");
	if (!avaliable) {
		int i = 0;
		const char config_data[] = "{\"enable\": true, \"current_ver\": 0}";
		fputs(config_data, fc);
		config_data_parsed = cJSON_Parse(config_data);
	}
	else {
		void* cfg = malloc(512);
		char* config_data = (char*)cfg;
		fgets(config_data, 512, fc);
		if (strlen(config_data) == 0) {
			free(cfg);
			char config_data2[] = "{\"enable\": true, \"current_ver\": 0}";
			fputs(config_data2, fc);
			config_data_parsed = cJSON_Parse(config_data2);
		}
		else {
			config_data_parsed = cJSON_Parse(config_data);
			free(cfg);
		}
	}

	fclose(fc);
	
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif

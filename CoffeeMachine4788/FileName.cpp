#include <iostream>
using namespace std;

class CoffeeMachine {

private:
    int bean;   // 원두의 양

public:
    CoffeeMachine();
    ~CoffeeMachine();

    void start();  // 원두 확인 후 메뉴 선택으로 이동

private:
    void refillBean();          // 원두 부족 시 보충 여부 확인
	void selectMenu();          // 메뉴 선택 (1.아이스 / 2.커피, 이외 번호는 재선택, 참고로 아이스랑 핫이랑 음료양이 달라서 메뉴 선택에서 나눴고 그에따라서 추출 시간도 달라질거같아서..분리해서 생각함!)
    void makeIce();             // 아이스 커피: 얼음 준비 안내 후 추출
    void makeHot();             // 따뜻한 커피: 화상 주의 안내 후 추출
    void extract(int seconds);  // 커피 추출 (물, 원두 소비)
};

CoffeeMachine::CoffeeMachine() {
    bean = 0;
    cout << "커피머신 켜졌어요!" << endl;
}

CoffeeMachine::~CoffeeMachine() {
    cout << "커피머신 끌게요~ 안녕!" << endl;
}

void CoffeeMachine::refillBean() {
    int choice;
    cout << "앗 원두가 부족해요ㅠ 채울까요? (1.응 / 2.ㄴㄴ): ";
    cin >> choice;

    if (choice == 1) {
        bean = 100;
        cout << "원두 채웠어요!" << endl;
    }
    else {
        cout << "알겠어요~ 커피머신 끌게요!" << endl;
        exit(0);
    }
}

void CoffeeMachine::makeIce() {
    cout << "얼음 미리 넣어두세요~~" << endl;
    extract(5);
}

void CoffeeMachine::makeHot() {
    cout << "뜨거우니까 조심하세요!" << endl;
    extract(7);
}

void CoffeeMachine::extract(int seconds) {
    cout << "커피 내리는 중..." << endl;
    for (int i = seconds; i > 0; i--) {
        cout << "앞으로 " << i << "초,,," << endl;
    }
    bean -= 10;
    cout << "커피 다 됐어요! >3< " << endl;
}

void CoffeeMachine::selectMenu() {
    int choice;
    while (true) {
        cout << "어떤 거 드실래요? (1.아이스 / 2. 핫): ";
        cin >> choice;

        if (choice == 1) {
            makeIce();
            break;
        }
        else if (choice == 2) {
            makeHot();
            break;
        }
        else {
            cout << "1이나 2만 눌러주세요 - ''- " << endl;
        }
    }
}

void CoffeeMachine::start() {
    while (bean < 10) {
        refillBean();
    }
    selectMenu();
}

int main() {
    CoffeeMachine m1;
    m1.start();

    return 0;
}

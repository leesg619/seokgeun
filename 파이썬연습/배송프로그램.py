from datetime import datetime,timedelta

def menu_print(menu):
    print(menu)

    
def print_deliveryType():
    print('오늘 날짜 : ' ,datetime.today().strftime("%Y년%m월%d일"))
    option = int(input('1.로켓배송(1일)  2. 퀵배송(2일)  3. 일반배송(3일)\n>>>'))
    return option

wallet=20000
buy_list=['고등어','소고기','라면']
list=('고등어','소고기','라면')
menu = {'고등어': 2000, '쌀': 5000, '소고기': 3000, '아이스크림': 1000, '라면': 1000}
sum=0

while (len(buy_list)!=0):
    menu_print(menu)
    buy=input('사고자 하는 물품을 입력하세요.')

    if buy not in list:
        print('심부름 목록에 해당 물품이 없습니다. 다시 입력해 주세요.\n')
    elif buy not in buy_list:
        print('이미 구입한 물품입니다. 다시 입력해 주세요.\n')
    else:
        price=menu.get(buy, 0)
        wallet-=price
        sum+=price
        buy_list.remove(buy)
        print(buy, '를(을) 구매하였습니다. 카드 잔액은 ', wallet, '원입니다.\n')

print('심부름 목록에 있는 상품들을 모두 구매하였습니다. 구매한 목록은', list, '이며, 총 구매 가격은', sum, '원입니다.')


print('\n***배송 유형을 선택합니다.***\n')

option = print_deliveryType()
if option == 1:
        edt = datetime.now() + timedelta(days=1)
elif option == 2:
        edt = datetime.now() + timedelta(days=2)
else :
        edt = datetime.now() + timedelta(days=3)

print('배송될 날짜는 : ' ,edt.strftime("%Y년%m월%d일"), '입니다')

print('심부름값을 포함한 총 비용은 : ',sum*1.3,'원입니다.')

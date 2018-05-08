#include "listnode.h"

ListNode::ListNode()
{
    this->room_num = 0;
    this->room_price = 0;
}

ListNode::ListNode(const ListNode &n)
{
    this->room_num = n.room_num;
    this->room_price = n.room_price;
}

ListNode &ListNode::operator =(const ListNode &n)
{
    this->room_num = n.room_num;
    this->room_price = n.room_price;
}

void ListNode::set_room(int roomNum)
{
    this->room_num = roomNum;
}



double ListNode::price_gen()
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::normal_distribution<double> distrN(350.0, 12.0);
        double price = distrN(e);

        return price;
}




void ListNode::set_price(double price){
    this->room_price = price;
}


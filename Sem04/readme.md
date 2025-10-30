# Семинар №4 по СДА - Свързани списъци.

Време е да пристъпим към същинската част на курса, а именно към структурите от данни. 

Какво беше структура от данни? - начин за подреждане на данните в удобен за употреба формат. 

Как сме свикнали да подреждаме данните си? В масиви - статични (когато броят им е предварително
известен) и динамични (когато не знаем броят им). По-често стигаме до употребата на динамични масиви. Те обаче изискват повече менижиране на използваната памет. За да не ни се налага 
непрекъснато да мислим за нея, винаги можем да си обвием динамичното масивче в клас. Е, стандартно това се случва в добре познатата ни структура от данни, а именно - вектор. 

## `std::vector`
Стандартният вектор представлява "обвит" в клас динамичен масив, който сам се грижи за използваната от него памет - заделя я и я изтрива, когато е необходимо. 

> [!IMPORTANT]
> Заделянето на самата памет става чрез `operator new`, 
> а конструирането на самите обекти - чрез `placement new` върху вече заделената памет. Изтриването на самите обекти става чрез извикването на техните **деструктори**, а самата памет се 
> изтрива с `operator delete`.

```c++
template<class T>
class vector
{
private:
	T* _data;
	size_t _size;
	size_t _capacity;
	static const int RESIZE_FACTOR = 2;

public:
    //methods
};
```

Нека разгледаме един от основните му методи - `push_back()`. 
```c++
template <class T>
void vector<T>::push_back(const T& value)
{
	if (_capacity == _size)
		reserve(_capacity * GROWTH_FACTOR);

	new(_data[size++]) T(value);
}

```

Както можем да видим, в повечето случаи сложността на метода ни е константна - извършваме проверка и заделяне на памет. Но когато `_size` ни стане равно на `_capacity`, векторът увеличава заделената от него памет, в която пази данните. Това става чрез метода `reserve` :
```c++
template <class T>
void vector<T>::reserve(size_t n)
{
	if (n <= _capacity)
		return;

	T* new_data = static_cast<T*>(operator new(n * sizeof(T)));

	for (size_t i = 0; i < _size; i++)
		new (&new_data[i]) T(std::move(_data[i]));

	operator delete(_data, capacity() * sizeof(T));

	_data = new_data;
	_capacity = n;
}
```

 Този метод има линейна сложност. Съответно от време на време ще ни се налага да извършваме операцията `push_back` не в константно, а в линейно време. Оттам идва амортизирана сложност на операцията - О(1), защото все по-рядко ще ни се налага да правим reserve с нарастването на обема на данните. И все пак, когато ни се наложи, ще имаме сложност O(n) - нашия worst-case.

 Нека сега разгледаме още една от операциите, а именно - `insert`:
 ```c++
template <class T>
void vector<T>::insert(const iterator<T>& pos, const T& el)
{
	int pos_offs = pos - begin();
	if (pos_offs >= _size)
		throw std::out_of_range("Iterator out of bounds");

	if (_size == _capacity)
		reserve(_capacity * GROWTH_FACTOR);

	_size++;

	for (size_t i = _size - 1; i > pos_offs; i--)
	{
		new (&_data[i]) T(std::move(_data[i - 1]));
		_data[i - 1].~T();
	}

	new (&_data[pos_offs]) T(el);
}
```
Както забелязваме, метода ни намира позицията, на която трябва да поставим дадения елемент, и shift-ва всички елементи, стоящи вдясно от него, с 1 позиция (респективно с брой позиции, равен на броя на вмъкваните елементи, ако става дума за range insertion). Съответно тук сложността на метода ни е линейна по броя на отместванията. 

За метода `erase` аналогично отново можем да определим, че сложността ни е линейна по броя на отместванията + броя на изтритите елементи:
```c++
template <class T>
void vector<T>::erase(const iterator<T>& first, const iterator<T>& last)
{
	int deleted_count = last - first;
	if (deleted_count <= 0)
		return;

	int begin_offs = first - begin();
	int end_offs = last - begin();

	if (last != end())
	{
		for (size_t i = end_offs; i < _size; i++)
			new (&_data[begin_offs++]) T(std::move(_data[i]));
	}

	for (size_t i = end_offs; i < _size; i++)
		_data[i].~T();

	_size -= deleted_count;
}
```

Когато в дадена ситуация ни се налага да правим множество `insert` и `erase` операции, то можем да си зададем въпроса - това ли е най-подходящата структура от данни, която мога да използвам? 

Ами нека разгледаме още една структура от данни - свързан списък. 

Свързаният списък се дели на два вида - singly linked list или едносвързан списък, и doubly linked list или двусвързан. 

## Едносвързан списък
<img width="398" alt="image" src="https://github.com/user-attachments/assets/d73608d7-edaf-485f-9c0f-57ff8f495cda">

Едносвързаният списък представлява темплейтна структура от данни, в която елементите са т.нар. Nodes или възли. Всеки възел представлява структурка, която има указател към следващия елемент и съдържа в себе си едно поленце данни от типа на темплейта. Нека погледнем набързо как би изглеждал един Node:
```c++
template <class T>
struct node
{
	node<T>* _next;
	T _value;

	node() : _next{ nullptr }, _value() {};
	node(const T& value) : _value(value), _next{ nullptr } {};
	node(T&& value) : _value(std::move(value)), _next{ nullptr } {};

	template <class ...Args>
	node(Args ...args) : _next{ nullptr }, _value(std::forward<Args>(args)...) {}
};
```

Засега не обръщайте внимание на конструкторите - те ще ни трябват, когато разгледаме цялата имплементация на едносвързания списък. 

На първо място какво ни показва това? За разлика от вектора, тук липсва ***locality***, т.е. елементите не са разположени последователно. Адресите са разположени случайно из паметта и просто всеки елемент знае къде се намира този след него. 

Представете си, че обикаляте стаи и във всяка стая имате листче, на което пише коя е следващата стая, в която трябва да отидете, като нямате право да се връщате в предишната. Например, започвате от стая №01, в нея намирате листче, на което пише "стая №325", в 325 има листче с надпис "стая №200" и в 200 вече няма листче. Тази последователност от стаи описва точно един едносвързан списък: 01 -> 325 -> 200. 

Стандартната имплементация на свързания списък (`std::forward_list`) съдържа в себе си два указателя - към първия (head-указател) и към последния елемент (tail-указател) на колекцията от данни. Съответно като добавяме елемент в началото на колекцията, ние просто трябва да "закачим" неговия next-указател за първия елемент (head). Аналогично, когато добавяме елемент в края на колекцията, трябва да закачим next-указателя на tail-a за него. Както може би вече се досещате, това става за константно време - винаги извършваме константен брой операции. Тази сложност ни позволява винаги да пазим точното количество памет, което ни е необходимо, и да нямаме нужда от reserve или resize методи. 

Когато става дума за добавяне на елемент на дадена позиция, има значение дали искаме да го insert-нем преди позицията, или след нея. За да вмъкнем елемент между два други, ние трябва да разкачим левия от десния, да закачим левия за елемента и да закачим елемента за десния. Insert преди позицията ще изисква да стигнем до предходния елемент, което ще наложи обхождане на елементите от първия натам. Както се досещаме, това ще стане в линейно време. Затова в стандартната имплементация на списъка имаме метод само за вмъкване на елемента след подадената ни позиция, т.е. имаме `insert_after`, който се извършва в константно (О(1)) време:
```c++
template <class T>
iterator<T> forward_list<T>::insert_after(const iterator<T>& pos, const T& el)
{
	if (!pos._node_ptr)
		throw std::invalid_argument("Node ptr is null");

	if (pos == c_before_begin())
	{
		push_front(el);
		return _head;
	}

	node<T>* to_insert = new node<T>(el);
	node<T>* temp = pos._node_ptr->_next;
	pos._node_ptr->_next = to_insert;
	to_insert->_next = temp;

	if (!temp)
		_tail = to_insert;
	
	return pos;
}
```

Тук имаме и друг интересен метод, който ни позволява да вмъкнем друг свързан списък на дадена позиция в нашия и то отново за константно време. Това става чрез метода `splice_after`:
```c++
// Moves elements from another forward_list to *this. The elements are inserted after the element pointed to by pos
template <class T>
void forward_list<T>::splice_after(const iterator<T>& pos, forward_list<T>& other)
{
	if (!pos._node_ptr || !other._head)
		return;

	auto temp = pos._node_ptr->_next;
	pos._node_ptr->_next = other._head;
	other._tail->_next = temp;

	if (pos == c_before_begin())
		_head = other._head;

	if (!temp)
		_tail = other._tail;

	other._head = other._tail = nullptr;
	other._before_head->_next = nullptr;
}
```
Както можем да видим, тук просто "закачаме" списъка след node-a на подадената позиция, а "опашката" му закачаме за следващия елемент от нашия списък (този след елемента на позиция pos).  

Премахването на елемент от дадена позиция се случва в линейно време в общия случай отново по същите причини, поради които вмъкването е линейно. Затова тук имаме метод `erase_after()`, който ни позволява да изтрием елемент след дадена позиция в константно време:
```c++
template <class T>
iterator<T> forward_list<T>::erase_after(const iterator<T>& pos)
{
	if (!pos._node_ptr)
		throw std::invalid_argument("Node ptr is null");

	if (pos == c_before_begin())
	{
		pop_front();
		return _head;
	}

	node<T>* to_erase = pos._node_ptr->_next;
	if (to_erase)
	{
		if (!to_erase->_next) //to_erase is tail
		{
			pos._node_ptr->_next = to_erase->_next;
			delete to_erase;
			_tail = pos._node_ptr;
			return end();
		}
		else
		{
			pos._node_ptr->_next = to_erase->_next;
			delete to_erase;
			return pos._node_ptr->_next;
		}
	}

	return end();
}
```

Съответно когато ще правим множество добавяния и премахвания на елементи и locality-то не ни е от жизнена важност, `std::forward_list`-a е много подходяща за нас структура. 

> [!NOTE]
> Интересен факт за нея е, че има *sentinel* в началото, който се намира преди _head елемента. Той осигурява сигурността, че всеки елемент от списъка си има предшественик. Помага за по-лесното изпълнение на операции като `push_front`, `pop_front`, `emplace_front` и т.н. Методът `before_begin()` връща итератор към него.


## Двусвързан списък
<img width="475" alt="image" src="https://github.com/user-attachments/assets/ac7e2d2d-07a8-420f-b3d4-b24fd7bcbbc8">


Двусвързаният списък също е темплейтна структура от данни, съставена също от Node-ове. Тук обаче те имат и един допълнителен указател, сочещ към предходния елемент:
```c++
template <class T>
struct node
{
	node<T>* _next;
	node<T>* _prev;
	T _value;

	node() : _next{ nullptr }, _prev{ nullptr }, _value() {}
	node(const T& value) : _next{ nullptr }, _prev{ nullptr }, _value(value) {}
	node(T&& value) : _next{ nullptr }, _prev{ nullptr }, _value(std::move(value)) {}

	template <class ...Args>
	node(Args&& ...args) : _next{ nullptr }, _prev{ nullptr }, _value(std::forward<Args>(args)...) {}

};
```
Тук отново нямаме ***locality*** и пазим точното количество памет, което ни е необходимо. 

Ако се върнем на примера със стаите, тук вече ни е позволено да се върнем в предишната, т.е. от зала 01 отиваме в зала 325, но в 325 имаме ново листче, на което пише "зала №01". Съответно в зала 200 имаме листче, на което пише "зала №325". Ако трябва да представим списъка тук, той ще изглежда така: 01 <-> 325 <-> 200. 

Стандартната имплементация на двусвързания списък `std::list` е доста интересна. Бихме предположили, че пази указатели към първия елемент, към последния, или пък само към първия елемент. Всъщност се оказва, че в `std::list`-a пазим само един указател. Този указател обаче не сочи нито към първия, нито към последния елемент на списъка. Добре, тогава накъде сочи?

Подобно на едносвързания списък, тук също имаме **sentinel node** и указателя, който пазим, сочи именно към него. Указателят към следващия му елемент (_sentinel->_next) сочи към първия елемент на списъка, а този към предишния (-sentinel->_prev) - към последния елемент от списъка. Каква информация ни дава това? Че двусвързаният списък е имплементиран циклично. Sentinel node-a винаги съществува и е валиден. По този начин се осигурява по-лесно добавяне в началото и в края на списъка без да ни се налага да следим _head и _tail указателите дали са правилно насочени. Освен това ни спестява памет. 

Друг интересен факт за двусвързания списък е, че пази в себе си променлива за size-a. Съответно, ако за да намерим size-a на едносвързан списък, трябва да го обходим целия, което налага извършване на операцията в линейно време, то при двусвързаният списък това става в константно време О(1). 

Операцията `insert` тук отново е константна като сложност, понеже метода отново приема iterator към позицията, на която трябва да insert-нем елемента. Тук единствените разлики с едносвързания списък са, че ни се налага да "разкачаме" и "закачаме" и **_prev**-указателчетата, а и елемента се вмъква на позицията **преди** подадената като аргумент:

```c++
template <class T>
iterator<T> list<T>::insert(const iterator<T>& pos, const T& el)
{
	if (!pos._node_ptr)
		throw std::runtime_error("Invalid iterator");

	if (pos == begin())
	{
		push_front(el);
		return begin();
	}

	if (pos == (end() - 1))
	{
		push_back(el);
		return end();
	}

	node<T>* to_insert = new node<T>(el);
	node<T>* curr = pos._node_ptr;
	node<T>* prev = pos._node_ptr->_prev; // prev keeps previous node

	curr->_prev = to_insert; // we insert to_insert before curr
	to_insert->_next = curr; // attaching to_insert to curr
	prev->_next = to_insert; // we attached to_insert to prev node
	to_insert->_prev = prev; // we attached previous node to to_insert

	_size++;

	return pos;
}
```

При двусвързания списък имаме също метода `splice`, който отново ни позволява да вмъкнем друг свързан списък в нашия в **константно време О(1)**. Отново, разликите с едносвързания списък са, че ни се налага да "разкачаме" и "закачаме" и **_prev**-указателчетата, а и елемента се вмъква на позицията **преди** подадената като аргумент:
```c++
template <class T>
void list<T>::splice(const iterator<T>& pos, list<T>& other)
{
	if (!pos._node_ptr || !other.size())
		return;

	auto other_h = other._sentinel->_next;
	auto other_t = other._sentinel->_prev;
	other._sentinel->_next = other._sentinel->_prev = nullptr;
	other._size = 0;

	auto curr = pos._node_ptr;
	auto prev = curr->_prev;

	prev->_next = other_h;
	other_h->_prev = prev; // now we attached prev to other`s head

	curr->_prev = other_t;
	other_t->_next = curr; // now we attached curr to other`s tail

	_size += other._size;
}
```

Премахването на елемент отново е константно, като ако имаме подадена позиция, то премахваме елемета **преди** нея: 
```c++
template <class T>
iterator<T> list<T>::erase(const iterator<T>& pos)
{
	if (!pos._node_ptr)
		throw std::runtime_error("Invalid iter");

	if (pos == begin())
	{
		pop_front();
		return begin();
	}

	if (pos == --end())
	{
		pop_back();
		return end();
	}

	node<T>* prev = pos._node_ptr->_prev;
	node<T>* next = pos._node_ptr->_next;
	node<T>* curr = pos._node_ptr;

	prev->_next = next;
	next->_prev = prev;

	delete curr;

	_size--;

	return { next };
}
```

Тук, както забелязваме, нямаме нужда да гледаме дали трием (добавяме) елемент на сегашната, предходната или следващата позиция. Причината е, че имаме адресите както на следващите, така и на предходните елементи на даден възел.

> [!IMPORTANT]
> И при двата списъка намирането на даден елемент става в линейно време О(n). Нямаме достъп с пряка индексация, както при вектора. Достъпа до елементи се осъществвява чрез **итератори**. 

Съответно, ако трябва да направим паралел между двата списъка, можем да обобщим следното:
- Едносвързаният списък е по-лесен за реализация и използва по-малко памет, но е по-ограничен откъм навигация и ефективност при добавяне и изтриване на елементи - винаги добавяме и трием елемента след подадената позиция. 
- Двусвързаният списък предлага по-голяма гъвкавост при навигация и е по-ефективен при изтриване, но е по-сложен за реализация и заема повече памет.

В общия случай ще ни се налага да ползваме `std::list`, но изборът между двете зависи много от изискванията откъм памет и бързина на операциите. 

---
# Задачи 🌻
- [**Remove Duplicates From A Lined Lists**](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
- [**Reverse a linked list**](https://www.hackerrank.com/challenges/reverse-a-linked-list/problem)
- [**Merge Two Sorted Linked Lists**](https://leetcode.com/problems/merge-two-sorted-lists/)
- [**Cycle Detection**](https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem)
- [**Intersection of two linked lists**](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)
- [**Заместване на елемент 1**](https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3729/problem)
- [**Заместване на елемент 2**](https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3730/problem)
- [**Remove Nth Elemenet From End of Linked List**](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

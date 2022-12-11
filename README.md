# Redwood_test
Тестовое задание следующее:
Инструментарий разработки: QT SDK
Описание: Приложение представляет собой типичный "игровой инвентарь".
Ссылка на демонстрацию работы клиентской части:
https://yadi.sk/i/RNyvVKemyCWbL
I. Описание GUI и взаимодействия пользователя с ним.
1. При запуске приложения первым открывается виджет "Главное меню". В
нём две кнопки: "Новая игра" и "Выход".
2. Нажатие на кнопку "Выход" приводит к закрытию программы.
3. Нажатие на кнопку "Новая игра" инициирует начало новой игры.
4. После нажатия на кнопку новая игра открывается доступ к виджету
"Игровое поле".
6. На игровом поле слева расположен виджет QTableWidget - "Инвентарь",
размерностью 3х3, все ячейки таблицы инвентаря квадратной формы.
7. На игровом поле справа расположен виджет предмета, содержащий предмет
"Яблоко", являющийся источником для Drag'n'Drop'a в ячейки Инвентаря.
Яблоки в этом виджете бесконечные, можно брать из источника и
перетаскивать в инвентарь неограниченное количество раз.
8. При перетаскивании яблока из источника в инвентарь оно появляется в
той ячейке инвентаря, в которую осуществлено перетаскивание.
Так же возможно перетаскивание предмета внутри ячеек инвентаря. Внутри
инвентаря предметы перетаскиваются всей пачкой,
т.е. к примеру, если в ячейке было 3 яблока, перетаскиваются все три.
9. При повторном перетаскивании яблока из источника в инвентарь в ту
ячейку, где уже есть яблоко, количество яблок в этой ячейке
увеличивается на 1.
Справа снизу от яблока в ячейке инвентаря находится цифра, указывающая
на количество яблок в ячейке. К примеру, было одно яблоко, цифра 1,
после перетаскивания стало два яблока, стала цифра два.
10. При клике правой кнопкой мыши по ячейке инвентаря с яблоком
происходит уменьшение количества яблок в ячейке. Если там было одно
яблоко, то картинка яблока
исчезает. Если яблок больше одного, цифра должна уменьшится на единицу.
11. При исчезновении яблока по правому клику мыши воспроизводится звук
откусывания яблока (подойдет любой, найти можно в интернет).
12. Над виджетами "Инвентарь" и "Яблоко" находится кнопка "Главное
меню". При нажатии на кнопку игровое поле блокируется и отображается
виджет, описаный в п. 1.
II. Описание классов программы и описание её работы.
1. Класс "Предмет". Должен описывать предмет инвентаря и содержать в
себе поля: Тип предмета, изображение предмета (путь к изображению в
ресурсах).
2. Класс "Инвентарь". Должен описывать инвентарь и содержать поля размер
(количество ячеек), а так же поля,
описывающие, в какой ячейке сколько находится предметов и каких
предметов.
3. Класс "База данных". Необходим для управления базой данных.
Подключается к базе данных и выполняет запросы. Использовать
QSqlDatabase.
4. База данных SQLite. Содержит в себе таблицы "Инвентарь" и "Предмет",
которые хранят данные указанных выше классов.
Здесь должны отражаться названия предметов, нажождение их в каких либо
ячейках инвентаря. Конкретная организация таблиц на ваше усмотрение.
5. Другие классы и объекты, нужные вам, на ваше усмотрение.
Общие требования: Использовать классы и фичи Qt: containers, signals and
slots, widgets, sockets и т.д.
STL использовать можно, но желательно только в тех ситуациях, когда
по-другому нельзя.
Хранить количество предметов в инвентаре и описание предметов в базе
данных SQLite.
Реализовать класс инвентаря и класс, описывающий предмет (т.е. в нашем
примере это было яблоко).
Обязательно наличие исходного кода. Обязательно краткое описание
методов.
Задание призвано проверить уровень понимания ООП, степень владения Qt,
знание паттернов проектирования,
навыки работы с БД.


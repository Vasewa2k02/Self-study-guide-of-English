#include "stdafx.h"

int menu()
{
	cout << "\tМеню:" << endl;
	cout << "1. Словарь" << endl;
	cout << "2. Грамматика" << endl;
	cout << "3. Проверка знаний" << endl;
	cout << "4. Настройки" << endl;
	cout << "0. Закончить работу" << endl;
	cout << "(Выберите пункт) ";
	cin >> choice;
	system("cls");
	return choice;
}

int menu_1()
{
	cout << "\tМеню:" << endl;
	cout << "1. Добавить слово" << endl;
	cout << "2. Посмотреть словарь" << endl;
	cout << "3. Исправить слово" << endl;
	cout << "4. Удалить слово" << endl;
	cout << "0. Назад" << endl;
	cout << "(Выберите пункт) ";
	cin >> choice;
	system("cls");
	return choice;
}

int menu_2()
{
	cout << "\tМеню:" << endl;
	cout << "1. Present Simple" << endl;
	cout << "2. Future Simple" << endl;
	cout << "3. Past Simple" << endl;
	cout << "0. Назад" << endl;
	cout << "(Выберите пункт) ";
	cin >> choice;
	system("cls");
	return choice;
}

int menu_3()
{
	cout << "\tМеню:" << endl;
	cout << "1. Словарный запас" << endl;
	cout << "2. Грамматика" << endl;
	cout << "0. Назад" << endl;
	cout << "(Выберите, что хотите учить) ";
	cin >> choice;
	system("cls");
	return choice;
}

void menu_3_1()
{
	cout << "\tМеню:" << endl;
	cout << "1. Посмотреть пометки слова" << endl;
	cout << "2. Посмотреть часть речи слова" << endl;
	cout << "3. Посмотреть общую статистику" << endl;
	cout << "0. Закончить проверку знаний" << endl << endl;
	cout << " Введите перевод следующего слова или нужный вариант меню: " << endl;
}

int menu_3_2()
{
	cout << "\tМеню:" << endl;
	cout << "1. Present Simple" << endl;
	cout << "2. Future Simple" << endl;
	cout << "3. Past Simple" << endl;
	cout << "0. Назад" << endl;
	cout << "(Выберите время для изучения) ";
	cin >> choice;
	system("cls");
	return choice;
}

void menu_3_2_1(int time)
{
	system("cls");
	cout << " Изучаемое время: ";
	switch (time)
	{
	case 1:
		cout << "Present Simple";
		break;
	case 2:
		cout << "Future Simple";
		break;
	case 3:
		cout << "Past Simple";
		break;
	}
	cout << endl << endl;
	cout << "\tМеню:" << endl;
	cout << " 0. Закончить проверку знаний" << endl << endl;
	cout << " Введите перевод следующего предложения(учитывая изучаемое время и число существительного) или нужный пункт меню:" << endl;
}

int menu_4()
{
	cout << "\tМеню:" << endl;
	cout << "1. Изменить кол-во повторений слова для вычёркивания его из списка изучаемых(сейчас " << settings.numForLearned << ")" << endl;
	cout << "2. Выбрать вариант изучения(для словаря)" << endl;
	cout << "0. Назад" << endl;
	cout << "(Выберите пункт) ";
	cin >> choice;
	system("cls");
	return choice;
}

void grammarAid(int a)
{
	switch (a)
	{
	case 1:
		cout << "   Время Present Simple обозначает действие в настоящем в широком смысле слова. Оно употребляется для обозначения обыч-" << endl;
		cout << " ных, регулярно повторяющихся или постоянных действий, например, когда мы говорим о чьих-либо привычках, режиме дня," << endl;
		cout << " расписании и т. д., т. е. Present Simple обозначает действия, которые происходят в настоящее время, но не привязаны " << endl;
		cout << " именно к моменту речи." << endl;
		cout << "   Английский глагол во временной форме Present Simple почти всегда совпадает со своей начальной, то есть указанной в" << endl;
		cout << " словаре, формой без частицы to. Лишь в 3-ем лице единственного числа к ней нужно прибавить окончание -s: I work – he" << endl;
		cout << " works. Если глагол оканчивается на -s, -ss, -sh, -ch, -x, -o, то к нему прибавляется окончание -es: I wish – he wishes." << endl;
		cout << " К глаголам на -y с предшествующей согласной тоже прибавляется окончание -es, а -y заменяется на -i-: I try – he tries." << endl;
		cout << "   Для того, чтобы построить вопросительное предложение, перед подлежащим нужно поставить вспомогательный глагол: Do you" << endl;
		cout << " like rock?(Тебе нравится рок?); Does he speak Spanish?(Он говорит по-испански?)." << endl;
		cout << "   В отрицательных предложениях тоже используется вспомогательный глагол do/does, но не перед подлежащим, а перед гла-" << endl;
		cout << " голом. После него прибавляется отрицательная частица not: I do not like black coffee(Я не люблю чёрный кофе); She does" << endl;
		cout << " not smoke(Она не курит)." << endl;
		cout << "   Глагол to be (быть) всегда является особенным и его употребление во времени Present Simple зависит от подлежащего." << endl;
		cout << " Он имеет 3 разных формы: am(для 1-го лица единственного числа : I), is(для 3-го лица единственного числа: she/he/it)," << endl;
		cout << " are(для 1-го, 2-го и 3-го лица множественного числа : we/you/they): I am ready — Я готов; She is ready — Она готова;" << endl;
		cout << " We are ready — Мы готовы." << endl;
		cout << " Утверждение: I, you, we, they(he, she, it) + verb(+ -s)\tI(you, we, they)(he, she, it) + am(are)(is) + noun" << endl;
		cout << " Вопрос: Do(does) + I, you, we, they(he, she, it) + verb?\tAm(are)(is) + I(you, we, they)(he, she, it) + noun" << endl;
		cout << " Отрицание: I,you,we,they(he,she,it) + do(does) not + verb\tI(you,we,they)(he,she,it) + am(are)(is) not + noun" << endl << endl;
		break;
	case 2:
		cout << "   Future Simple Tense (или просто Future Simple) — это простое будущее время в английском языке. Мы используем Future" << endl;
		cout << " Simple, чтобы высказать предположения о будущем или о событиях, которые точно произойдут и на которые мы не можем" << endl;
		cout << " повлиять. Также, для обещаний, угроз, предупреждений и предостережений." << endl;
		cout << "   Future Simple образуется при помощи одного вспомогательного глагола will. Он употребляется со всеми числами и лицами." << endl;
		cout << " Не важно, говорим мы о 1-м лице единственного числа (I), о 3-м лице единственного числа (She / He / It) или же обо всех" << endl;
		cout << " лицах множественного числа (We / You / They) — во всех случаях употребляем вспомогательный глагол will." << endl;
		cout << "   Для того, чтобы составить утвердительное предложение в Future Simple — нужно добавить глагол will после подлежащего," << endl;
		cout << " но перед смысловым глаголом без частицы to: I will read - Я буду читать; He will play - Он будет играть." << endl;
		cout << "   Отрицательная конструкция времени Future Simple образуется при помощи добавления частицы not после вспомогательного" << endl;
		cout << " глагола will: You will not write - Ты не будешь писать;  We will not work - Мы не будем работа." << endl;
		cout << "   В вопросительной конструкции вспомогательный глагол will переносится в начало предложения, за ним следует подлежащее" << endl;
		cout << " и смысловой глагол без частицы to: Will you buy? - Ты купишь? Will she call - Она позвонит?" << endl;
		cout << "   Особый глагол to be (am / is / are) в простом будущем времени приобретает форму will be. В вопросах подлежащее как бы" << endl;
		cout << " «разбивает собой» эту форму: Will you be a teacher? - Ты будешь учителем? I will be a doctor - Я буду доктором." << endl;
		cout << " She will not be a mother - Она не будет матерью" << endl;
		cout << " Утверждение: I, you, we, they, he, she, it + will + verb\tI, you, we, they, he, she, it + will be + noun" << endl;
		cout << " Вопрос: Will + I, you, we, they, he, she, it + verb?\t\tWill + I, you, we, they, he, she, it + be + noun" << endl;
		cout << " Отрицание: I, you, we, they, he, she, it + will not + verb\tI, you, we, they, he, she, it + will not be + noun" << endl << endl;
		break;
	case 3:
		cout << "   Past Simple Tense - это простое прошедшее время. но используется, если событие произошло в определенное время в" << endl;
		cout << " прошлом и не продолжается в настоящем. Past Simple указывает на простое действие в прошлом, регулярные или повторяв-" << endl;
		cout << " шиеся действия в прошлом или перечисление последовавших действий в прошлом." << endl;
		cout << "   Чтобы образовать Past Simple, нужно употребить вторую форму глагола. У большинства глаголов она образуется путем" << endl;
		cout << " добавления окончания “-ed” к инфинитиву, но есть и неправильные глаголы. Их нужно просто запомнить. Если глагол закан-" << endl;
		cout << " чивается на “e“, добавляется просто “d“, если глагол заканчивается “y“, то она заменяется на “i” перед ): to walk –>" << endl;
		cout << " walked; to smile –> smiled; to cry –> cried." << endl;
		cout << "   Отрицательные и вопросительные предложения в Past Simple строятся с помощью добавления формы прошедшего времени гла-" << endl;
		cout << " гола “to do – did” и инфинитива смыслового глагола: Did you read? - Ты читал? We did not work - Мы не работали." << endl;
		cout << "   Глагол to be (am / is / are) в простом прошедшем времени имеет две формы, так как он является неправильным. Для" << endl;
		cout << " I, he she, it - was; для you, we, they - were: I was a teacher - Я был учителем. Were you a doctor? - Ты был доктором?" << endl;
		cout << " She was not a mother - Она не была мамой" << endl;
		cout << " Утверждение: I, you, we, they, he, she, it + verb(2nd form)\tI, he, she, it(you, we, they) + was(were) + noun" << endl;
		cout << " Вопрос: Did + I, you, we, they, he, she, it + verb?\t\tWas(were) + I, he, she, it(you, we, they) + noun" << endl;
		cout << " Отрицание: I, you, we, they, he, she, it + did not + verb\tI, he, she, it(you, we, they) + was(were) not + noun" << endl << endl;
		break;
	default:
		break;
	}
	cout << " "; system("pause");
	system("cls");
}
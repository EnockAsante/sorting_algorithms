#include "sort.h"

/**
 * print_listint_t - print doubly linked list
 * @h: head of list
 * Return: 0 if none or len
 */
size_t print_listint_t(const listint_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);
	while (h)
	{
		printf("%d", h->n);
		if (h->next)
			printf(", ");
		h = h->next;
		len++;
	}
	printf("\n");
	return (len);
}

/**
 * listint_len - doubly linked list len
 * @h: head of list
 * Return: 0 if none or len
 */
size_t listint_len(const listint_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);
	while (h)
	{
		h = h->next;
		len++;
	}
	return (len);
}


/**
 * loop_back - find head of list
 * @list: list
 */
void loop_back(listint_t **list)
{
	listint_t *h;

	if (!list)
		return;
	h = *list;
	while (h->prev)
		h = h->prev;
}
/**
 * insertion_sort_list- print doubly linked list
 * @list: head of list
 * Return: 0 if none or len
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *cur, *nxt, *prv;

	if (!list || !*list)
		return;

	while (1)
	{
		cur = *list;
		while (cur)
		{
			if (cur->prev && cur->prev->n > cur->n)
			{
				nxt = cur->next;
				prv = cur->prev;

				if (prv->prev)
					prv->prev->next = cur;
				else
					*list = cur;
				cur->prev = prv->prev;
				prv->prev = cur;
				prv->next = nxt;
				if (nxt)
					nxt->prev = prv;
				cur->next = prv;

				loop_back(list);
				print_listint_t(*list);

				break;

			}
			cur = cur->next;
		}
		if (!cur)
			break;
	}
}

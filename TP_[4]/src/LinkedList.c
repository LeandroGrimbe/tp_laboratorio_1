#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));
	if (this!=NULL)
	{
		this->size=0;
		this->pFirstNode=NULL;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int len=-1;
	if(this!=NULL)
	{
		len = (this->size);
	}

	return len;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* aux = NULL;
	int	listLen = ll_len(this);
	if(this!=NULL && nodeIndex>-1 && nodeIndex<listLen)
	{
		aux = this->pFirstNode;
		if(nodeIndex>0)
		{
			int i;
			for(i=0;i<nodeIndex;i++)
				aux = aux->pNextNode;
		}
	}
	return aux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int retorno=-1,
		listLen = ll_len(this);
	if(this!=NULL && nodeIndex>-1 && nodeIndex<(listLen+1))
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		if(newNode!=NULL)
		{
			newNode->pElement = (Node*)pElement;

			Node* aux = NULL;
			aux = this->pFirstNode;
			if(nodeIndex>0)
			{
				int i;
				for(i=0;i<nodeIndex-1;i++)
					aux = aux->pNextNode;

				newNode->pNextNode = aux->pNextNode;
				aux->pNextNode = newNode;
			}
			else
			{
				newNode->pNextNode = aux;
				this->pFirstNode = newNode;
			}

			retorno=0;
			this->size++;
		}
	}

	return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int retorno=-1;
	if(this!=NULL)
	{
		int listLen = ll_len(this);
		int nodeIndex = listLen;

		if(addNode(this,nodeIndex,pElement)==0)
			retorno=0;
	}

	return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* element = NULL;
	int	listLen = ll_len(this);
	if(this!=NULL && index>-1 && index<listLen)
	{
		Node* aux = getNode(this,index);
		if (aux!=NULL)
			element = aux->pElement;
	}

	return element;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int retorno=-1,
		listLen = ll_len(this);
	if(this!=NULL && index>-1 && index<listLen)
	{
		Node* aux = getNode(this,index);
		if (aux!=NULL)
		{
			aux->pElement = pElement;
			retorno=0;
		}
	}

	return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int retorno=-1,
		listLen = ll_len(this);
	if(this!=NULL && index>-1 && index<listLen)
	{
		Node* aux = getNode(this,index);
		if (aux!=NULL)
		{
			if(index==0)
			{
				this->pFirstNode = aux->pNextNode;
			}
			else
			{
				Node* aux2 = getNode(this,index-1);
				aux2->pNextNode = aux->pNextNode;
			}

			free(aux);
			aux = NULL;

			this->size--;
			retorno=0;
		}
	}

	return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int retorno=-1;
	if(this!=NULL)
	{
		int i,
			listLen = ll_len(this);

		for(i=listLen-1;i==0;i--)
		{
			Node* aux = getNode(this,i);
			if (aux!=NULL)
			{
				if(i==0)
				{
					this->pFirstNode = NULL;
				}

				free(aux);
				aux = NULL;

				this->size--;
				retorno=0;
			}
		}
	}

	return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int retorno=-1;
	if(this!=NULL)
	{
		if(ll_clear(this)==0)
		{
			free(this);
			this = NULL;
			retorno=0;
		}
	}

	return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno=-1;
    if(this!=NULL)
    {
    	int i,
			listLen = ll_len(this);
    	for(i=0;i<listLen;i++)
    	{
    		Node* aux = getNode(this,i);
    		if(aux->pElement==pElement)
    		{
    			retorno=i;
    			break;
    		}
    	}
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
		int listLen = ll_len(this);
		if(listLen>0)
			retorno=0;
		else
			retorno=1;
    }

    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int retorno=-1,
		listLen = ll_len(this);
	if(this!=NULL && index>-1 && index<listLen+1)
	{
		if(addNode(this,index,pElement)==0)
			retorno=0;
	}

	return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* element = NULL;
	int	listLen = ll_len(this);
	if(this!=NULL && index>-1 && index<listLen)
	{
		Node* aux = getNode(this,index);
		if (aux!=NULL)
		{
			element = aux->pElement;
			this->size--;

			free(aux);
			aux = NULL;
		}
	}

	return element;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno=-1;
    if(this!=NULL)
    {
    	int i,
			listLen = ll_len(this);

    	retorno=0;
    	for(i=0;i<listLen;i++)
    	{
    		Node* aux = getNode(this,i);
    		if(aux!=NULL && aux->pElement==pElement)
    		{
    			retorno=1;
    			break;
    		}
    	}
    }

    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno=-1;
    if(this!=NULL && this2!=NULL)
    {
    	int i,
			listLen = ll_len(this2),
			similarNodes=0;

    	retorno=0;
    	for(i=0;i<listLen;i++)
    	{
    		Node* aux = getNode(this,i);
    		Node* aux2 = getNode(this2,i);
    		if(aux!=NULL && aux2!=NULL && aux->pElement==aux2->pElement)
    		{
    			similarNodes++;
    		}
    	}

    	if(similarNodes==listLen)
    		retorno=1;
    }

    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subArray = NULL;
    int listLen = ll_len(this);
    if(this!=NULL && from>-1 && from<listLen && to>-1 && to<listLen+1)
    {
    	subArray = ll_newLinkedList();

    	int i;
    	void* aux = NULL;
    	for(i=from;i<to;i++)
    	{
    		aux = ll_get(this, i);
    		ll_add(subArray,aux);
    	}
    }

    return subArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {
    	cloneArray = ll_newLinkedList();
    	void* aux = NULL;

    	int i,
			listLen = ll_len(this);
    	for(i=0;i<listLen;i++)
    	{
    		aux = ll_get(this, i);
    		ll_add(cloneArray,aux);
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int retorno=-1;
	if(this!=NULL && pFunc!=NULL && (order==1 || order==0))
	{
		int i,
			j,
			change,
			listLen = ll_len(this);

		void* aux1 = NULL;
		void* aux2 = NULL;

		for(i=0;i<listLen-1;i++)
		{
			for(j=i+1;j<listLen;j++)
			{
				aux1=ll_get(this, i);
				aux2=ll_get(this, j);

				change = pFunc(aux1,aux2);
				if((change>0 && order==1) || (change<0 && order==0))
				{
					ll_set(this,i,aux2);
					ll_set(this,j,aux1);
				}
			}
		}
		retorno=0;
	}

	return retorno;
}

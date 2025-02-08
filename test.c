// #include <stdio.h>
// #include <stdlib.h>

// // Define the t_list structure
// typedef struct s_list
// {
//     int content;
//     int index;
//     struct s_list *next;
// } t_list;

// // Function to create a new node
// t_list *create_node(int content)
// {
//     t_list *new_node = (t_list *)malloc(sizeof(t_list));
//     new_node->content = content;
//     new_node->index = -1; // Initially set index to -1
//     new_node->next = NULL;
//     return new_node;
// }

// // Function to calculate the size of the list
// int ft_lstsize(t_list *lst)
// {
//     int size = 0;
//     t_list *tmp = lst;
//     while (tmp)
//     {
//         size++;
//         tmp = tmp->next;
//     }
//     return size;
// }

// // Function to find the "best" (min) value in the list
// int ft_best(t_list *lst)
// {
//     int min = lst->content;
//     t_list *tmp = lst->next;

//     while (tmp)
//     {
//         if (tmp->content > min)
//             min = tmp->content;
//         tmp = tmp->next;
//     }
//     return min;
// }

// // Function to assign indices to the list
// void ft_index(t_list **s_a)
// {
//     t_list *tmp1;
//     int i;
//     int min;

//     if (!s_a || !*s_a)
//         return ;
    
//     i = 0;
//     tmp1 = *s_a;
    
//     // Reset all indices to -1
//     while (tmp1)
//     {
//         tmp1->index = -1;
//         tmp1 = tmp1->next;
//     }

//     // Assign indices based on the minimum values
//     while (i < ft_lstsize(*s_a))
//     {
//         min = ft_best(*s_a);  // Find the minimum value in the list
//         tmp1 = *s_a;

//         // Find the node with the minimum value and unassigned index
//         while (tmp1)
//         {
//             if (min > tmp1->content && tmp1->index == -1)
//                 min = tmp1->content;
//             tmp1 = tmp1->next;
//         }

//         tmp1 = *s_a;

//         // Assign the index to the node with the minimum value
//         while (tmp1->content != min)
//             tmp1 = tmp1->next;
//         tmp1->index = i++;  // Assign the current index and increment it
//     }
// }

// // Helper function to print the list
// void print_list(t_list *lst)
// {
//     t_list *tmp = lst;
//     while (tmp)
//     {
//         printf("Value: %d, Index: %d\n", tmp->content, tmp->index);
//         tmp = tmp->next;
//     }
// }

// int main()
// {
//     // Create a linked list with some values
//     t_list *head = create_node(50);
//     head->next = create_node(20);
//     head->next->next = create_node(40);
//     head->next->next->next = create_node(10);
//     head->next->next->next->next = create_node(30);

//     // Call ft_index to assign indices
//     ft_index(&head);

//     // Print the list to verify the indices
//     print_list(head);

//     // Free the memory
//     t_list *tmp;
//     while (head)
//     {
//         tmp = head;
//         head = head->next;
//         free(tmp);
//     }

//     return 0;
// }


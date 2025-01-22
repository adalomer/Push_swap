#include "push_swap.h"
#include <stdio.h> // Sadece debug için, silinebilir
#include <stdlib.h>

void ft_recursive_sort(t_stack **a, t_stack **b, int len) {
    int *temp_array;
    int  pivot;
    int  i;
    int  ra_count;
    int  pb_count;
    int  rotations;
    t_stack *temp;

    if (len <= 3) {
        if (len == 1)
          return;
        else if (len == 2) {
            if ((*a)->index > (*a)->next->index)
                ft_sa(a);
        } else if (len == 3)
            ft_sort_three(a);
        return;
    }

    // Pivot Seçimi
    temp_array = (int *)malloc(sizeof(int) * len);
    if (!temp_array) {
        ft_error(a);
        return;
    }
    temp = *a;
    i = 0;
    while (i < len) {
        temp_array[i] = temp->index;
        temp = temp->next;
        i++;
    }
    i = 1;
    while (i < len) {
        int key = temp_array[i];
        int j = i - 1;
        while (j >= 0 && temp_array[j] > key) {
            temp_array[j + 1] = temp_array[j];
            j--;
        }
        temp_array[j + 1] = key;
        i++;
    }
    pivot = temp_array[len / 2];
    free(temp_array);

    // Eleman Dağıtımı
    i = 0;
    ra_count = 0;
    pb_count = 0;
    rotations = 0;

    while (i < len ) {
      if ((*a)->index >= pivot)
          rotations++;
        if ((*a)->index < pivot) {
          while(rotations > 0 && pb_count < len - (len / 2))
          {
            ft_ra(a);
            ra_count++;
            rotations--;
          }
            ft_pb(a, b);
            pb_count++;
            rotations = 0; // rotations sıfırlanıyor
        } else {
          if(pb_count < len - (len / 2))
          {
            ft_ra(a);
            ra_count++;
          }
        }
        i++;
    }

    // Gereksiz ra yapılmışsa düzeltiliyor
    i = 0;
    while (i < ra_count) {
      ft_rra(a);
      i++;
    }
    ra_count = 0;

    ft_recursive_sort(a, b, len - pb_count);
    ft_recursive_sort(b, a, pb_count);

    while (pb_count--)
        ft_pa(a, b);
}

void ft_quick_sort(t_stack **a, t_stack **b, int len) {
    if (ft_is_sorted(*a))
        return;
    if (len <= 3) {
        if (len == 2) {
            if ((*a)->index > (*a)->next->index)
                ft_sa(a);
        } else if (len == 3) {
            if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index) {
                ft_ra(a);
                if ((*a)->index > (*a)->next->index)
                    ft_sa(a);
            } else if ((*a)->index > (*a)->next->index) {
                ft_sa(a);
            } else if ((*a)->next->index > (*a)->next->next->index) {
                ft_rra(a);
                if ((*a)->index > (*a)->next->index)
                    ft_sa(a);
            }
        }
        return;
    }
    ft_recursive_sort(a,b,len);
}
void ft_sort_three(t_stack **a) {
    if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index) {
        ft_ra(a);
        if ((*a)->index > (*a)->next->index)
            ft_sa(a);
    } else if ((*a)->index > (*a)->next->index) {
        ft_sa(a);
    } else if ((*a)->next->index > (*a)->next->next->index) {
        ft_rra(a);
        if ((*a)->index > (*a)->next->index)
            ft_sa(a);
    }
}
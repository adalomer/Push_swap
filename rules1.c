#include "push_swap.h"
#include <unistd.h>

void    ft_rr(t_stack** heada,t_stack** headb)
{
    ft_rarb(heada,3);
    ft_rarb(headb,3);
    write(1,"rr\n",3);
}

void    ft_rrr(t_stack** heada, t_stack** headb)
{
    ft_rrarrb(heada,3);
    ft_rrarrb(headb,3);
    write(1,"rrr\n",4);
}
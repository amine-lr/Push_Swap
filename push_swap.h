
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_flags
{
	t_strategy	strategy;
	int			bench;
}	t_flags;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_op_node
{
	char			*operation;
	struct s_op_node	*next;
}	t_op_node;

int		calculate_disorder(int *stack_a, int length);
void	push_swap(t_list *stack_a, int length);
int		main(int argc, char *argv[]);
int		search_duplicates(int *stack_a, int length);
int		stack_a_is_correct(char *stack_a);
int		*transform_argv(char **argv, int *length);
void	ft_array_to_list(int *array_a, t_list **stack_a, int length);
int		validate_integer_range(const char *str);
void	error_output(void);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putnbr_fd(int n, int fd);
t_flags	parse_flags(int argc, char **argv, int *start_index);
void	simple_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head);
void	medium_sort(t_list **stack_a, t_list **stack_b, t_op_node **ops_head);
void	complex_sort(t_list **stack_a, t_list **stack_b, int *array, int length, t_op_node **ops_head);
double	calculate_disorder_percentage(int *array, int length);
void	adaptive_sort(t_list **stack_a, t_list **stack_b, int *array, int length, t_op_node **ops_head);
void	benchmark_output(int *array, int length, t_flags flags, t_op_node *ops);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

t_op_node	*create_op_node(char *op_name);
void		record_operation(t_op_node **ops_head, char *op_name);
void		print_operations(t_op_node *ops_head);
void		free_operations(t_op_node *ops_head);

#endif

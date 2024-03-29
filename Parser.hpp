/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:30:59 by aribeiro          #+#    #+#             */
/*   Updated: 2017/06/16 15:51:28 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "Lexer.hpp"

enum instructions {
	PUSH = 0,
	POP,		// 1
	DUMP,		// 2
	ASSERT,		// 3
	ADD,		// 4
	SUB,		// 5
	MUL,		// 6
	DIV,		// 7
	MOD,		// 8
	PRINT,		// 9
	EXIT,		// 10
	SHOW,		// 11
	SWAP,		// 12
	REVERSE		// 13
};

enum eOperandType {
	INT8 = 0,
	INT16,		// 1
	INT32,		// 2
	FLOAT,		// 3
	DOUBLE		// 4
};

struct s_scanner2 {
	int				line_nb;
	int				instruction;
	int				type;
	long double		value;
	std::string		original_line;
	bool			error;
	int				error_position_lexer;
	std::string		error_verbose;
};

class Parser {
	public:
		Parser(void);
		Parser(Parser const & cpy);
		~Parser(void);
		Parser &	operator=(Parser const & );
		Lexer &		get_lexer(void);
		//parsing _____________________________________________
		void	set_parsing(void);
		void	init_scanner2(int j, int line_nb, int instruction, int type, int value,
								std::string original_line, bool error, int error_position_lexer);
		int		get_instruction(std::string lexeme);
		int		get_type(std::string lexeme);
		void	set_error_verbose(int j, std::string str1, int position_lexer);
		void	debug_print_parsing(void);

		std::vector<s_scanner2>		get_parsing(void) const;
		static const std::string	_type[5];

	private:
		Lexer 						*_lexer;
		std::vector<s_scanner2>		_parsing;
		// static ______________________________________________
		static const std::string	_instruct[14];
		static const std::string	_verbose[16];
};

#endif

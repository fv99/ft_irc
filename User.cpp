/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:25 by cgray             #+#    #+#             */
/*   Updated: 2024/11/13 15:56:34 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User(){}
User::User(const User &src) : _nick(src._nick), _user(src._user), _host(src._host){*this = src;}
User &User::operator = (const User &src){return (*this);}
User::User(std::string nick, std::string user, std::string host) : _nick(nick), _user(user), _host(host), _auth(false), _op(false)
{

}
User::~User()
{
	std::cout << "user destructor: " << _user << "\n";
	if (_fd != -1)
		close(_fd);
}

int	User::get_fd() {return _fd;}
std::string	User::get_nick(){return _nick;}
std::string	User::get_user(){return _user;}
std::string	User::get_read_buf(){return _read_buf;}
bool	User::get_auth(){return _auth;}
bool	User::get_op(){return _op;}

void	User::set_fd(int fd) {_fd = fd;}
void	User::set_auth(bool auth){_auth = auth;}
void	User::set_op(bool op_status){_op = op_status;}
void	User::set_send_buf(std::string buf){_read_buf += buf;}

// channels
void User::join_channel(Channel* channel)
{
    _channels.insert(channel);
}

void User::leave_channel(Channel* channel)
{
    _channels.erase(channel);
}

const std::set<Channel*>& User::get_channels() const
{
    return _channels;
}
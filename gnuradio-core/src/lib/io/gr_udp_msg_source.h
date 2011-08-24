/*
 * Copyright 2011 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_GR_UDP_MSG_SOURCE_H
#define INCLUDED_GR_UDP_MSG_SOURCE_H

#include <gr_msg_queue.h>

class gr_udp_msg_source;
typedef boost::shared_ptr<gr_udp_msg_source> gr_udp_msg_source_sptr;

gr_udp_msg_source_sptr gr_make_udp_msg_source(int port,
                                              gr_msg_queue_sptr msgq);

/*!
 * \brief Gather received items into messages and insert into msgq
 * \ingroup sink_blk
 */
class gr_udp_msg_source {
};

#endif /* INCLUDED_GR_UDP_MSG_SOURCE_H */
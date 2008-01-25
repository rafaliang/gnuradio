/* -*- c++ -*- */
/*
 * Copyright 2006,2007 Free Software Foundation, Inc.
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
#ifndef INCLUDED_GR_HIER_BLOCK2_H
#define INCLUDED_GR_HIER_BLOCK2_H

#include <gr_basic_block.h>

/*!
 * \brief public constructor for gr_hier_block2

 */
gr_hier_block2_sptr gr_make_hier_block2(const std::string &name,
                                        gr_io_signature_sptr input_signature,
                                        gr_io_signature_sptr output_signature);

class gr_hier_block2_detail;

/*!
 * \brief gr_hier_block2 - Hierarchical container class for gr_block's
 * \ingroup internal
 *
 */
class gr_hier_block2 : public gr_basic_block
{
private:
  friend class gr_hier_block2_detail;
  friend gr_hier_block2_sptr gr_make_hier_block2(const std::string &name,
						 gr_io_signature_sptr input_signature,
						 gr_io_signature_sptr output_signature);
  
  /*!
   * \brief Private implementation details of gr_hier_block2
   */
  gr_hier_block2_detail *d_detail;
  
protected: 
  gr_hier_block2(const std::string &name,
		 gr_io_signature_sptr input_signature,
		 gr_io_signature_sptr output_signature);
  
public:
  virtual ~gr_hier_block2();
  
  void connect(gr_basic_block_sptr block);

  void connect(gr_basic_block_sptr src, int src_port, 
	       gr_basic_block_sptr dst, int dst_port);

  void disconnect(gr_basic_block_sptr block);

  void disconnect(gr_basic_block_sptr src, int src_port,
		  gr_basic_block_sptr dst, int dst_port);

  void disconnect_all();
  virtual void lock();
  virtual void unlock();

  gr_flat_flowgraph_sptr flatten() const;
};

inline gr_hier_block2_sptr make_hier_block2_sptr(gr_basic_block_sptr block) {
  return boost::dynamic_pointer_cast<gr_hier_block2, gr_basic_block>(block);
}

#endif /* INCLUDED_GR_HIER_BLOCK2_H */

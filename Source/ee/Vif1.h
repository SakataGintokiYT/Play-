#pragma once

#include "Vif.h"

class CGIF;

class CVif1 : public CVif
{
public:
					CVif1(unsigned int, CVpu&, CGIF&, uint8*, uint8*);
	virtual			~CVif1();

	void			Reset() override;
	void			SaveState(Framework::CZipArchiveWriter&) override;
	void			LoadState(Framework::CZipArchiveReader&) override;

	uint32			GetTOP() const override;

	uint32			ReceiveDMA(uint32, uint32, uint32, bool) override;

private:
	void			ExecuteCommand(StreamType&, CODE) override;

	void			Cmd_DIRECT(StreamType&, CODE);
	void			Cmd_UNPACK(StreamType&, CODE, uint32) override;

	void			PrepareMicroProgram() override;

	CGIF&			m_gif;

	uint32			m_BASE;
	uint32			m_OFST;
	uint32			m_TOP;
	uint32			m_TOPS;
};

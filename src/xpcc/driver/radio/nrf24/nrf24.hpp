#ifndef XPCC__NRF24_HPP
#define XPCC__NRF24_HPP

namespace xpcc
{

namespace nrf24
{

    /* Raw bits */
    constexpr uint8_t Bit0 = (1 << 0);
    constexpr uint8_t Bit1 = (1 << 1);
    constexpr uint8_t Bit2 = (1 << 2);
    constexpr uint8_t Bit3 = (1 << 3);
    constexpr uint8_t Bit4 = (1 << 4);
    constexpr uint8_t Bit5 = (1 << 5);
    constexpr uint8_t Bit6 = (1 << 6);
    constexpr uint8_t Bit7 = (1 << 7);


    enum class Register : uint8_t
    {
        
        CONFIG = 0x00,          ///< Configuration Register
        EN_AA = 0x01,           ///< Enable 'Auto Acknowledgment'
        EN_RX_ADDR = 0x02,	    ///< Enabled RX Addresses
        SETUP_AW = 0x03,	    ///< Setup of Address Widths
        SETUP_RETR = 0x04,	    ///< Setup of Automatic Retransmission
        RF_CH = 0x05,           ///< RF Channel
        RF_SETUP = 0x06,        ///< RF Setup Register
        STATUS = 0x07,          ///< Status Register
        OBSERVE_TX = 0x08,      ///< Transmit observe register
        RPD = 0x09,             ///< Received Power Detector
        RX_ADDR_P0 = 0x0a,      ///< Receive address data pipe 0
        RX_ADDR_P1 = 0x0b,      ///< Receive address data pipe 1
        RX_ADDR_P2 = 0x0c,      ///< Receive address data pipe 2
        RX_ADDR_P3 = 0x0d,      ///< Receive address data pipe 3
        RX_ADDR_P4 = 0x0e,      ///< Receive address data pipe 4
        RX_ADDR_P5 = 0x0f,      ///< Receive address data pipe 5
        TX_ADDR = 0x10,         ///< Transmit address
        RX_PW_P0 = 0x11,        ///< Number of bytes in RX payload in pipe 0
        RX_PW_P1 = 0x12,        ///< Number of bytes in RX payload in pipe 1
        RX_PW_P2 = 0x13,        ///< Number of bytes in RX payload in pipe 2
        RX_PW_P3 = 0x14,        ///< Number of bytes in RX payload in pipe 3
        RX_PW_P4 = 0x15,        ///< Number of bytes in RX payload in pipe 4
        RX_PW_P5 = 0x16,        ///< Number of bytes in RX payload in pipe 5
        FIFO_STATUS = 0x17,     ///< FIFO Status Register
        DYNPD = 0x1c,           ///< Enable dynamic payload length
        FEATURE = 0x1d          ///< Feature Register
    };

    /* CONFIG register */
    enum class Config : uint8_t
    {
        PRIM_RX      = Bit0,
        PWR_UP       = Bit1,
        CRC0         = Bit2,
        EN_CRC       = Bit3,
        MASK_MAX_RT  = Bit4,
        MASK_TX_DS   = Bit5,
        MASK_RX_DR   = Bit6
    };

    /* EN_AA register */
    enum class EnAA : uint8_t
    {
        ENAA_P0 = Bit0,
        ENAA_P1 = Bit1,
        ENAA_P2 = Bit2,
        ENAA_P3 = Bit3,
        ENAA_P4 = Bit4,
        ENAA_P5 = Bit5
    };

    /* EN_RXADDR register */
    enum class EnRxAddr : uint8_t
    {
        ERX_P0 = Bit0,
        ERX_P1 = Bit1,
        ERX_P2 = Bit2,
        ERX_P3 = Bit3,
        ERX_P4 = Bit4,
        ERX_P5 = Bit5
    };
    
    /* SETUP_AW register */
    enum class SetupAw : uint8_t
    {
        AW = Bit0 | Bit1
    };
    
    /* SETUP_RETR register */
    enum class SetupRetr : uint8_t
    {
        ARC = Bit0 | Bit1 | Bit2 | Bit3,
        ARD = Bit4 | Bit5 | Bit6 | Bit7
    };
    
    /* RF_CH register */
    enum class RfCh : uint8_t
    {
        RF_CH = Bit0 | Bit1 | Bit2 | Bit3 | Bit4 | Bit5 | Bit6
    };
    
    /* RF_SETUP register */
    enum class RfSetup : uint8_t
    {
        RF_PWR       = Bit1 | Bit2,
        RF_DR_HIGH   = Bit3,
        PLL_LOCK     = Bit4,
        RF_DR_LOW    = Bit5,
        CONT_WAVE    = Bit7
    };
    
    /* STATUS register */
    enum class Status : uint8_t
    {
        TX_FULL  = Bit0,
        RX_P_NO  = Bit1 | Bit2 | Bit3,
        MAX_RT   = Bit4,
        TX_DS    = Bit5,
        RX_DR    = Bit6
    };
    
    /* OBSERVE_TX register */
    enum class ObserveTx : uint8_t
    {
        ARC_CNT  = Bit0 | Bit1 | Bit2 | Bit3,
        PLOS_CNT = Bit4 | Bit5 | Bit6 | Bit7
    };
    
    /* RPD register*/
    enum class Rpd : uint8_t
    {
        RPD = Bit0
    };
    
    /* RX_PW_P0 register */
    enum class RxPwP0 : uint8_t
    {
        RX_PW_P0 = Bit0 | Bit1 | Bit2 | Bit3 | Bit4 | Bit5
    };
    
    /* RX_PW_P1 register */
    enum class RxPwP1 : uint8_t
    {
        RX_PW_P1 = Bit0 | Bit1 | Bit2 | Bit3 | Bit4 | Bit5
    };
    
    /* RX_PW_P2 register */
    enum class RxPwP2 : uint8_t
    {
        RX_PW_P2 = Bit0 | Bit1 | Bit2 | Bit3 | Bit4 | Bit5
    };
    
    /* RX_PW_P3 register */
    enum class RxPwP3 : uint8_t
    {
        RX_PW_P3 = Bit0 | Bit1 | Bit2 | Bit3 | Bit4 | Bit5
    };
    
    /* RX_PW_P4 register */
    enum class RxPwP4 : uint8_t
    {
        RX_PW_P4 = Bit0 | Bit1 | Bit2 | Bit3 | Bit4 | Bit5
    };
    
    /* RX_PW_P5 register */
    enum class RxPwP5 : uint8_t
    {
        RX_PW_P5 = Bit0 | Bit1 | Bit2 | Bit3 | Bit4 | Bit5
    };
    
    /* FIFO_STATUS register */
    enum class FifoStatus : uint8_t
    {
        RX_EMPTY = Bit0,
        RX_FULL  = Bit1,
        TX_EMPTY = Bit4,
        TX_FULL  = Bit5,
        TX_REUSE = Bit6
    };
    
    /* DYNPD register*/
    enum class DynPd : uint8_t
    {
        DPL_P0 = Bit0,
        DPL_P1 = Bit1,
        DPL_P2 = Bit2,
        DPL_P3 = Bit3,
        DPL_P4 = Bit4,
        DPL_P5 = Bit5
    };
    
    /* FEATURE register */
    enum class Feature : uint8_t
    {
        EN_DYN_ACK   = Bit0,
        EN_ACK_PAY   = Bit1,
        EN_DPL       = Bit2
    };

    enum class Command : uint8_t
    {
    	R_REGISTER 			= 0b00000000,	///< 1 -  5 data bytes | lower 5 bit = Register address
    	W_REGISTER			= 0b00100000,	///< 1 -  5 data bytes | lower 5 bit = Register address
    	R_RX_PAYLOAD 		= 0b01100001,	///< 1 - 32 data bytes
    	W_TX_PAYLOAD 		= 0b10100000,	///< 1 - 32 data bytes
    	FLUSH_TX 			= 0b11100001,	///<      0 data bytes
    	FLUSH_RX 			= 0b11100010,	///<      0 data bytes
    	REUSE_TX_PL 		= 0b11100011,	///<      0 data bytes
    	R_RX_PL_WID 		= 0b01100000,	///<      1 data bytes
    	W_ACK_PAYLOAD 		= 0b10101000,	///< 1 - 32 data bytes | lower 3 bit = Pipe # (000 to 101)
    	W_TX_PAYLOAD_NOACK 	= 0b10110000,	///< 1 - 32 data bytes
    	NOP 				= 0b11111111	///<      0 data bytes
    };
}


template <typename Spi, typename Csn, typename Ce>
class Nrf24
{

public:
	static void
	initialize();


private:

	static void
	writeRegister(nrf24::Register, uint8_t& data, uint8_t length);

	static uint8_t
	writeCommand(nrf24::Command, uint8_t& data, uint8_t length);

private:
	static uint8_t status;

};

}

#include "nrf24_impl.hpp"

#endif

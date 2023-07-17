library ieee;
use ieee.std_logic_1164.all;
entity g2b_code is
port (g : in std_logic_vector(3 downto 0);
 b : out std_logic_vector(3 downto 0));
end g2b_code;
architecture g2b_arch of g2b_code is
begin
 b(3) <= g(3);
 b(2) <= g(3) xor g(2);
 b(1) <= g(3) xor g(2) xor g(1);
 b(0) <= g(3) xor g(2) xor g(1) xor g(0);
end g2b_arch;

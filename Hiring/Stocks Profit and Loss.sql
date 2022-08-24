
/*-----------------------------------------------------------------------

Stocks: Profit and loss
You have a passive income that you use to invest in stocks. You want to figure out how much profit you made through your investments.

All the stocks that you have invested in are listed in a table called stocks. This table also includes the price at which each stock was bought and sold.

Task

Write a query to fetch the stock_symbol of the stock and the profit or loss earned by it.

Notes:

A stock bought and sold can be uniquely identified by stock_id. 
Loss is denoted using a -ve sign.
Order the result by stock_symbol in ascending order.

Table description

Table name: stocks

Field

Type

description

transaction_id

String

Alphanumeric unique id for every transaction. It is the primary key.

stock_symbol

String

Symbol of the stock assigned for trading

stock_id

Integer

Unique id for every stock bought and sold

stock_value

Integer

Value at which the stock was bought or sold

transaction_type

String

Type of transaction consisting of either 'buy' or 'sell'

Output format

The output of the query will be consist of the following fields:

stock_symbol

profit/loss

Example

Sample input

stocks
transaction_id	stock_symbol	stock_id	stock_value	transaction_type
3NzvYFRVDf	FOX	2624	6653	sell
7T9FZx0qYl	CMCSA	7660	3064	buy
a8mssrRRgM	CMCSA	4361	3117	buy
B6w6QKEb65	AMZN	7292	6865	buy
bK0DNznLo3	CMCSA	2187	2618	buy
CHc1sObDLu	AMZN	7292	7313	sell
EtRfk6GDvQ	CMCSA	3478	3196	sell
H8uqIjeFrl	CMCSA	3472	3105	sell
inlplaCXeJ	FOX	4472	7398	sell
LZKuAk05RF	CMCSA	7660	3351	sell
olAKfuJazD	FOX	4472	7350	buy
oVLPDzpf7H	FOX	5833	8240	buy
Q9Zb60ysru	FOX	5833	7937	sell
QMd7gd9R3S	CMCSA	2187	2487	sell
wHXboJR5Us	FOX	7198	7998	sell
WVlbNOFkZ8	CMCSA	3478	2944	buy
XRybWue7jy	FOX	2624	6985	buy
yC51cuyOan	FOX	7198	7645	buy
zE1YzdyIXs	CMCSA	3472	3046	buy
zzLy89cJwp	CMCSA	4361	3384	sell
 

Sample output

stock_symbol	profit/loss
AMZN	448
CMCSA	734
FOX	-234


---------------------------------------------------------------------------------*/

select x as "stock_symbol" , sum(a.y) - sum(a.z) as "profit/loss" from 
(select c.stock_symbol as x, sum(c.stock_value) as y, sum(e.stock_value) as z from stocks as c, stocks as e 
where e.transaction_type = "buy" and c.transaction_type = "sell" and c.stock_id = e.stock_id group by c.stock_id,c.stock_symbol) as a group by x;
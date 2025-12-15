#ifndef MENUREPORTES_H
#define MENUREPORTES_H

void menuReportes();

void menuReportesClientes();
void menuReportesEmpleados();
void menuReportesFinancieros();

// Reportes de Clientes
void reporteClienteMasTransacciones();
void reporteMontoTransferenciasPorMes();
void reporteClientesPorLocalidad();
void reporteTop5ClientesMayorMonto();

// Reportes de Empleados (listo)
void reporteEmpleadosPorLocalidad();
void reporteEmpleadosActivosVsBaja();
void reporteEmpleadosPorRangoEdad();

// Reportes Financieros
void reporteSaldoTotalCuentas();
void reportePromedioTransacciones();
void reporteRankingCuentasMayorSaldo();

#endif
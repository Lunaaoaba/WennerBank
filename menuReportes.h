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
void reporteClientesConPrestamos();

// Reportes de Empleados
void reporteEmpleadoMasOperaciones();
void reporteMontoPrestamosPorMes();
void reportePromedioPrestamosPorEmpleado();
void reporteAltaEmpleadosPorMes();

// Reportes Financieros
void reporteSaldoTotalCuentas();
void reportePromedioTransacciones();
void reporteRankingCuentasMayorSaldo();

#endif